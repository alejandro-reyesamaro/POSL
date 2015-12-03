#include "posl_meta_solver.h"
#include "../solver/for_golfers_css.h"
#include <math.h>
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

POSL_MetaSolver::POSL_MetaSolver(vector<shared_ptr<POSL_Solver> > _solvers)
    : solvers(_solvers)
{}


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
                connection_operators.push_back(make_shared<ConnectionOperatorBroadcasting>(jacks_solvers_info, outlets_solvers_info));
            else if (current_declaration.Operator_Name == OP_CONNECTION_NC_NAME)
                connection_operators.push_back(make_shared<ConnectionOperatorNoConnection>(jacks_solvers_info));
            else if (current_declaration.Operator_Name == OP_CONNECTION_BP_NAME)
                connection_operators.push_back(make_shared<ConnectionOperatorBipartition>(jacks_solvers_info, outlets_solvers_info));
            else if (current_declaration.Operator_Name == OP_CONNECTION_RING_NAME)
                connection_operators.push_back(make_shared<ConnectionOperatorRin>(jacks_solvers_info, outlets_solvers_info));
            else
                throw "(POSL Exception) Not well coded connection operator (POSL_MetaSolver::POSL_MetaSolver)";

            jacks_solvers_info.clear();
            outlets_solvers_info.clear();
        }
    }

    for(unsigned int i = 0; i < connection_operators.size(); i++)
        connection_operators[i]->connect(scheduler);
}

void POSL_MetaSolver::solve(int argc, char **argv)
{
    int myid = 0;

    MPI_Comm_rank(MPI_COMM_WORLD,&myid);

    if(myid < scheduler->schedulerSize())
    {
        shared_ptr<POSL_Solver> solver = scheduler->getSolverAt(0);
        shared_ptr<PSP> psp(make_shared<PSP>(argc, argv, benchmark, myid));
        solver->solve(psp);
        cout << solver->show() << endl;
    }

    exit(0);
}












/*
int mainProcess(int myid)
{
    return (myid % 2 == 0) ? myid : myid - 1;
}

int neighborProcess(int myid, int numprocs)
{
    if(myid % 2 == 0 && myid == numprocs - 1) return - 1;
    return (myid % 2 == 0) ? myid + 1 : myid;
}
*/

void POSL_MetaSolver::solve(int argc, char **argv, shared_ptr<Benchmark> bench, unsigned int opt)
{
    if(opt == 0)
        solve_Default_NO(argc, argv, bench);
    else if (opt > 0 && opt < 100)
    {
        //int factor = 200/opt;
        //cout << factor << endl;
        solve_Default_50(argc, argv, bench, round(200/opt));
    }
    else if (opt >= 100)
        solve_Default_All(argc, argv, bench);
}

void POSL_MetaSolver::solve_Default_NO(int argc, char **argv, shared_ptr<Benchmark> bench)
{
    int myid, comm_size;

    MPI_Init(&argc, &argv);

    MPI_Comm_size(MPI_COMM_WORLD,&comm_size);
    MPI_Comm_rank(MPI_COMM_WORLD,&myid);

    shared_ptr<PSP> psp(make_shared<PSP>(argc, argv, bench, myid));

    int solver_index = 2;

    shared_ptr<POSL_Solver> solver = solvers[solver_index];
    solver->solve(psp);
    cout << solver->show() << endl;
    //cout << solver->show(psp->GetBenchmark()) << endl;
    exit(0);

    MPI_Finalize();
}

void POSL_MetaSolver::solve_Default_50(int argc, char **argv, shared_ptr<Benchmark> bench, int factor)
{
    int myid, comm_size;

    MPI_Init(&argc, &argv);

    MPI_Comm_size(MPI_COMM_WORLD,&comm_size);
    MPI_Comm_rank(MPI_COMM_WORLD,&myid);

    shared_ptr<PSP> psp(make_shared<PSP>(argc, argv, bench, myid));

    int solver_index;
    factor = min(factor, comm_size);
    //if(myid == 0)
    //    cout << "Factor: " << factor << endl;

    //*********************************************
    //        50 % Communication
    //*********************************************
    if(myid < comm_size/factor)
    {
        //psp->connectWith(comm_size/factor + myid);
        solver_index = 0;
        //cout << "Core " << myid << " conected with core " << comm_size/4 + myid << endl;
    }
    else if((myid >= comm_size/factor) && myid < comm_size/(factor/2))
        solver_index = 1;
    else
        solver_index = 2;

    shared_ptr<POSL_Solver> solver = solvers[solver_index];
    solver->solve(psp);
    cout << solver->show() << endl;
    //cout << solver->show(psp->GetBenchmark()) << endl;
    exit(0);

    MPI_Finalize();
}

void POSL_MetaSolver::solve_Default_All(int argc, char **argv, shared_ptr<Benchmark> bench)
{
    int myid, comm_size;

    MPI_Init(&argc, &argv);

    MPI_Comm_size(MPI_COMM_WORLD,&comm_size);
    MPI_Comm_rank(MPI_COMM_WORLD,&myid);

    shared_ptr<PSP> psp(make_shared<PSP>(argc, argv, bench, myid));

    int solver_index;

    //*********************************************
    //        All Communication
    //*********************************************
    if(myid < comm_size/2)
    {
        //psp->connectWith(comm_size/2 + myid);
        solver_index = 0;
        //cout << "Core " << myid << " conected with core " << comm_size/2 + myid << endl;
    }
    else
        solver_index = 1;

    shared_ptr<POSL_Solver> solver = solvers[solver_index];
    solver->solve(psp);
    cout << solver->show() << endl;
    //cout << solver->show(psp->GetBenchmark()) << endl;
    exit(0);

    MPI_Finalize();
}
