#pragma once

#include "operation_module.h"
#include "../data/neighborhood.h"

class AOM_NeighborhoodFunction : public OperationModule
{
    public:
        std::shared_ptr<ComputationData> execute(std::shared_ptr<PSP> psp, std::shared_ptr<ComputationData> input);
        virtual std::shared_ptr<Neighborhood> spcf_execute(std::shared_ptr<PSP> psp, std::shared_ptr<Solution> input) = 0;
};
