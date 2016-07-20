#pragma once

#include "../solver/posl_solver.h"
#include "connector_info.h"
#include "connection_operator.h"


class ConnectionOperatorNoConnection : public ConnectionOperator
{
    public:
        ConnectionOperatorNoConnection(std::vector<std::pair<std::shared_ptr<POSL_Solver>, ConnectorInfo> > _solvers);
        void connect(std::shared_ptr<Scheduler> scheduler);

    private:
        std::vector<std::pair<std::shared_ptr<POSL_Solver>, ConnectorInfo>> solvers;
};
