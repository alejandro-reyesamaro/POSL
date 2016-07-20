#pragma once

#include "../solver/posl_solver.h"
#include "connector_info.h"
#include "connection_operator.h"


class ConnectionOperatorBipartition : public ConnectionOperator
{
    public:
        ConnectionOperatorBipartition(std::vector<std::pair<std::shared_ptr<POSL_Solver>, ConnectorInfo> > _solver_jacks,
                                       std::vector<std::pair<std::shared_ptr<POSL_Solver>, ConnectorInfo> > _solver_outlets);
        void connect(std::shared_ptr<Scheduler> scheduler);

    private:
        std::vector<std::pair<std::shared_ptr<POSL_Solver>, ConnectorInfo>> solver_jacks;
        std::vector<std::pair<std::shared_ptr<POSL_Solver>, ConnectorInfo>> solver_outlets;
};
