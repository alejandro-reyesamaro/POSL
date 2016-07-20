#include "connection_strategy.h"
#include "../tools/tokens_definition.h"
#include "../connections/connection_operator_broadcasting.h"
#include "../connections/connection_operator_no_connection.h"
#include "../connections/connection_operator_bipartition.h"
#include "../connections/connection_operator_rin.h"
#include "../tools/tools.h"

ConnectionStrategy::ConnectionStrategy()
{
}

void ConnectionStrategy::declareConnection(ConnectionsDeclaration & conn_declaration,
                                           shared_ptr<Scheduler> scheduler,
                                           HashMap<string, shared_ptr<POSL_Solver>> & solver_list)
{
    for(int i = 0; i < conn_declaration.TopologySize; i++)
    {
        crateConnectionOperator(conn_declaration, i, solver_list);
        connection_operator->connect(scheduler);
        //scheduler->checkOut();
    }
}

void expand_solver_name(shared_ptr<POSL_Solver> solver, int topology_index)
{
    if(topology_index > 0)
        solver->expandSolverName("t" + Tools::int2str(topology_index+1));
}

void ConnectionStrategy::crateConnectionOperator(ConnectionsDeclaration & conn_declaration,
                                                 int topology_index,
                                                 HashMap<string, shared_ptr<POSL_Solver>> & solver_list)
{
    shared_ptr<POSL_Solver> solver_j, solver_o;
    string jack, outlet;

    for(unsigned int k = 0; k < conn_declaration.Jack_solvers.size(); k++)
    {
        solver_j = solver_list.mapOf(conn_declaration.Jack_solvers[k]);
        expand_solver_name(solver_j, topology_index);
        jack = (conn_declaration.Jacks.size() == 0) ? "" : conn_declaration.Jacks[k];
        jacks_solvers_info.push_back({solver_j, {jack, (conn_declaration.Operator_Name == OP_CONNECTION_NC_NAME) ? NON : JACK}});
    }

    if(conn_declaration.Operator_Name != OP_CONNECTION_NC_NAME)
        for(unsigned int k = 0; k < conn_declaration.Outlet_solvers.size(); k++)
        {
            solver_o = solver_list.mapOf(conn_declaration.Outlet_solvers[k]);
            expand_solver_name(solver_o, topology_index);
            outlet = conn_declaration.Outlets[k];
            outlets_solvers_info.push_back({solver_o, {outlet, OUTLET}});
        }

    if(conn_declaration.Operator_Name == OP_CONNECTION_BC_NAME)
        connection_operator = (make_shared<ConnectionOperatorBroadcasting>(jacks_solvers_info, outlets_solvers_info));
    else if (conn_declaration.Operator_Name == OP_CONNECTION_NC_NAME)
        connection_operator = (make_shared<ConnectionOperatorNoConnection>(jacks_solvers_info));
    else if (conn_declaration.Operator_Name == OP_CONNECTION_BP_NAME)
        connection_operator = (make_shared<ConnectionOperatorBipartition>(jacks_solvers_info, outlets_solvers_info));
    else if (conn_declaration.Operator_Name == OP_CONNECTION_RING_NAME)
        connection_operator = (make_shared<ConnectionOperatorRin>(jacks_solvers_info, outlets_solvers_info));
    else
        throw "(POSL Exception) Not well coded connection operator (ConnectionStrategy::crateConnectionOperator)";

    jacks_solvers_info.clear();
    outlets_solvers_info.clear();
}
