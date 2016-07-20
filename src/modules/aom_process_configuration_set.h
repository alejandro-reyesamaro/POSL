#pragma once

#include "operation_module.h"
#include "../data/configuration_set.h"

class AOM_ProcessConfigurationSet : public OperationModule
{
    public:
        std::shared_ptr<ComputationData> execute(std::shared_ptr<PSP> psp, std::shared_ptr<ComputationData> input);
        virtual std::shared_ptr<ConfigurationSet> spcf_execute(std::shared_ptr<PSP> psp, std::shared_ptr<ConfigurationSet> input) = 0;
};
