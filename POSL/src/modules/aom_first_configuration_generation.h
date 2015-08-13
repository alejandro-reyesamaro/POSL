#pragma once

#include "operation_module.h"
#include "../data/solution.h"

class AOM_FirstConfigurationGeneration : public OperationModule
{
    public:
        ComputationData * execute(PSP * psp, ComputationData * input);
        virtual Solution * spcf_execute(PSP * psp, Solution * input) = 0;
};
