#pragma once

#include "operation_module.h"
#include "../data/neighborhood.h"

class AOM_NeighborhoodFunction : public OperationModule
{
    public:
        ComputationData * execute(PSP * psp, ComputationData * input);
        virtual Neighborhood * spcf_execute(PSP * psp, Solution * input) = 0;
};
