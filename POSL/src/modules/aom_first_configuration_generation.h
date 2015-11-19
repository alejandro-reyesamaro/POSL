#pragma once

#include "operation_module.h"
#include "../data/seed.h"

class AOM_FirstConfigurationGeneration : public OperationModule
{
    public:
        AOM_FirstConfigurationGeneration(std::shared_ptr<Benchmark> bench);

        std::shared_ptr<ComputationData> execute(std::shared_ptr<PSP> psp, std::shared_ptr<ComputationData> input);
        virtual std::shared_ptr<Solution> spcf_execute(std::shared_ptr<PSP> psp, std::shared_ptr<Seed> input) = 0;

    protected:
        std::vector<Domain> domains;
};
