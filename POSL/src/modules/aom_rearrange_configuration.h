#pragma once

#include "operation_module.h"

class AOM_RearrangeConfiguration : public OperationModule
{
    public:
        std::shared_ptr<ComputationData> execute(std::shared_ptr<PSP> psp, std::shared_ptr<ComputationData> input);
        virtual std::shared_ptr<Solution> spcf_execute(std::shared_ptr<PSP> psp, std::shared_ptr<Solution> input) = 0;
};
