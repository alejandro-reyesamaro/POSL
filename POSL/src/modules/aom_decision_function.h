#pragma once

#include "operation_module.h"
#include "../data/solution.h"
#include "../data/decision_pair.h"

class AOM_DecisionFunction : public OperationModule
{
    public:
        ComputationData * execute(PSP * psp, ComputationData * input);
        virtual Solution * spcf_execute(PSP * psp, DecisionPair * input) = 0;
};
