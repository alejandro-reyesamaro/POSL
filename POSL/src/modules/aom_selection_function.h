#pragma once

#include "operation_module.h"
#include "../data/neighborhood.h"
#include "../data/decision_pair.h"

class AOM_SelectionFunction : public OperationModule
{
    public:
        shared_ptr<ComputationData> execute(shared_ptr<PSP> psp, shared_ptr<ComputationData> input);
        virtual shared_ptr<DecisionPair> spcf_execute(shared_ptr<PSP> psp, shared_ptr<Neighborhood> input) = 0;
};
