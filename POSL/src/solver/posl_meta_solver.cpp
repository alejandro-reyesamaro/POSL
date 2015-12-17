#include "posl_meta_solver.h"
#include "../tools/hash_map.h"
#include "../tools/coding_tools.h"
#include "../packing/posl_uncoder.h"
#include "../packing/connections_declaration.h"
#include "../tools/tokens_definition.h"
#include "../connections/connection_operator_broadcasting.h"
#include "../connections/connection_operator_no_connection.h"
#include "../connections/connection_operator_bipartition.h"
#include "../connections/connection_operator_rin.h"

#include <iostream>

#include "mpi.h"

using namespace std;

POSL_MetaSolver::POSL_MetaSolver(string path, int _comm_size, shared_ptr<Benchmark> bench)
    : comm_size(_comm_size),
      scheduler(make_shared<Scheduler>(_comm_size)),
      benchmark(bench)
{
    shared_ptr<PoslUncoder> posl_unc;
    pair<vector<string>, string> codes = CodingTools::splitDeclarationConnectionsFromFile(path);
    HashMap<string, shared_ptr<POSL_Solver>> solver_list = posl_unc->uncode_declarations(codes.first, bench);
    vector<ConnectionsDeclaration> connections = posl_unc->uncode_connections(codes.second);

    ConnectionsDeclaration current_declaration;
    shared_ptr<POSL_Solver> solver_j, solver_o;
    string jack, outlet;

    vector<pair<shared_ptr<POSL_Solver>, ConnectorInfo>> jacks_solvers_info, outlets_solvers_info;

    shared_ptr<ConnectionOperator> connection_operator;

    for(unsigned int i = 0; i < connections.size(); i++)
    {
        current_declaration = connections[i];
        for(int j = 0; j < current_declaration.Size; j++)
        {
            for(unsigned int k = 0; k < current_declaration.Jack_solvers.size(); k++)
            {
                solver_j = solver_list.mapOf(current_declaration.Jack_solvers[k]);
                jack = current_declaration.Jacks[k];
                jacks_solvers_info.push_back({solver_j, {jack, (current_declaration.Operator_Name == OP_CONNECTION_NC_NAME) ? NON : JACK}});
                if(current_declaration.Operator_Name != OP_CONNECTION_NC_NAME)
                {
                    solver_o = solver_list.mapOf(current_declaration.Outlet_solvers[k]);
                    outlet = current_declaration.Outlets[k];
                    outlets_solvers_info.push_back({solver_o, {outlet, OUTLET}});
                }
            }
            if(current_declaration.Operator_Name == OP_CONNECTION_BC_NAME)
                connection_operator = (make_shared<ConnectionOperatorBroadcasting>(jacks_solvers_info, outlets_solvers_info));
            else if (current_declaration.Operator_Name == OP_CONNECTION_NC_NAME)
                connection_operator = (make_shared<ConnectionOperatorNoConnection>(jacks_solvers_info));
            else if (current_declaration.Operator_Name == OP_CONNECTION_BP_NAME)
                connection_operator = (make_shared<ConnectionOperatorBipartition>(jacks_solvers_info, outlets_solvers_info));
            else if (current_declaration.Operator_Name == OP_CONNECTION_RING_NAME)
                connection_operator = (make_shared<ConnectionOperatorRin>(jacks_solvers_info, outlets_solvers_info));
            else
                throw "(POSL Exception) Not well coded connection operator (POSL_MetaSolver::POSL_MetaSolver)";

            connection_operator->connect(scheduler);
            scheduler->checkOut();

            jacks_solvers_info.clear();
            outlets_solvers_info.clear();
        }
    }
}

void POSL_MetaSolver::solve_in_parallel()
{
    int myid = 0;
    MPI_Comm_rank(MPI_COMM_WORLD,&myid);

    if(myid < scheduler->schedulerSize())
    {
        shared_ptr<POSL_Solver> solver = scheduler->getSolverAt(myid);
        shared_ptr<PSP> psp(make_shared<PSP>(benchmark, myid));
        solver->solve(psp);
        cout << solver->show(psp) << endl;
    }
    exit(0);
}

void POSL_MetaSolver::solve_sequentially()
{    
    shared_ptr<POSL_Solver> solver = scheduler->getFirstSequentialSolver();
    if(solver)
    {
        shared_ptr<PSP> psp(make_shared<PSP>(benchmark));
        solver->solve(psp);
        cout << solver->show(psp) << endl;
        exit(0);
    }    
}
