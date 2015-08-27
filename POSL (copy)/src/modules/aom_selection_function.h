#pragma once

#include "operation_module.h"
#include "../data/neighborhood.h"
#include "../data/decision_pair.h"

class AOM_SelectionFunction : public OperationModule
{
    public:
        ComputationData * execute(PSP * psp, ComputationData * input);
        virtual DecisionPair * spcf_execute(PSP * psp, Neighborhood * input) = 0;
};
