#pragma once

#include "operation_module.h"
#include "../data/solution.h"
#include "../data/decision_pair.h"

class AOM_DecisionFunction : public OperationModule
{
    public:
        shared_ptr<ComputationData> execute(shared_ptr<PSP> psp, shared_ptr<ComputationData> input);
        virtual shared_ptr<Solution> spcf_execute(shared_ptr<PSP> psp, shared_ptr<DecisionPair> input) = 0;
};
