#pragma once

#include "operation_module.h"
#include "../data/configuration_set.h"

class AOM_FirstConfigurationGenerationFromSet : public OperationModule
{
    public:
        AOM_FirstConfigurationGenerationFromSet(std::shared_ptr<Benchmark> bench);

        std::shared_ptr<ComputationData> execute(std::shared_ptr<PSP> psp, std::shared_ptr<ComputationData> input);
        virtual std::shared_ptr<Solution> spcf_execute(std::shared_ptr<PSP> psp, std::shared_ptr<ConfigurationSet> input) = 0;

    protected:
        std::shared_ptr<Domain> domain;
};
