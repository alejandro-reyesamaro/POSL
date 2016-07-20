#pragma once

#include "operation_module.h"
#include "../data/solution.h"
#include "../data/decision_pair.h"

class AOM_DecisionFunction : public OperationModule
{
    public:
        std::shared_ptr<ComputationData> execute(std::shared_ptr<PSP> psp, std::shared_ptr<ComputationData> input);
        virtual std::shared_ptr<Solution> spcf_execute(std::shared_ptr<PSP> psp, std::shared_ptr<DecisionPair> input) = 0;
};
