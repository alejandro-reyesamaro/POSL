#pragma once

#include "operation_module.h"
#include "../data/neighborhood.h"

class AOM_NeighborhoodFunction : public OperationModule
{
    public:
        shared_ptr<ComputationData> execute(shared_ptr<PSP> psp, shared_ptr<ComputationData> input);
        virtual shared_ptr<Neighborhood> spcf_execute(shared_ptr<PSP> psp, shared_ptr<Solution> input) = 0;
};
