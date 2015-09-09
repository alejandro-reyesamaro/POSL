#pragma once

#include "operation_module.h"
#include "../data/neighborhood.h"
#include "../data/decision_pair.h"

class AOM_SelectionFunction : public OperationModule
{
    public:
        std::shared_ptr<ComputationData> execute(std::shared_ptr<PSP> psp, std::shared_ptr<ComputationData> input);
        virtual std::shared_ptr<DecisionPair> spcf_execute(std::shared_ptr<PSP> psp, std::shared_ptr<Neighborhood> input) = 0;
};
