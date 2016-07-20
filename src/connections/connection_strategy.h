#pragma once

#include "connections_declaration.h"
#include "scheduler.h"
#include "connection_operator.h"

class ConnectionStrategy
{
    public:
        ConnectionStrategy();
        void declareConnection(ConnectionsDeclaration & conn_declaration,
                               shared_ptr<Scheduler> scheduler,
                               HashMap<string, shared_ptr<POSL_Solver>> & solver_list);

    protected:
        void crateConnectionOperator(ConnectionsDeclaration & conn_declaration,
                                     int topology_index,
                                     HashMap<string, shared_ptr<POSL_Solver>> & solver_list);

        shared_ptr<ConnectionOperator> connection_operator;
        vector<pair<shared_ptr<POSL_Solver>, ConnectorInfo>> jacks_solvers_info, outlets_solvers_info;
};
