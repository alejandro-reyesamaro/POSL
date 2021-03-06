#pragma once

#include "operation_module.h"
#include "aom_first_configuration_generation.h"
#include "../benchmarks/benchmark.h"
#include "strategy/random_permutation_configuration_strategy.h"

class OM_RandomPermutationGeneration : public AOM_FirstConfigurationGeneration
{
    public:
        OM_RandomPermutationGeneration(std::shared_ptr<Benchmark> bench);

        std::shared_ptr<Solution> spcf_execute(std::shared_ptr<PSP> psp, std::shared_ptr<Seed>);

        //! From Codable
        std::string codeToSend();

        virtual std::string Tag();

    protected:
        std::shared_ptr<RandomPermutationConfigurationStrategy> rconf_strategy;
        std::shared_ptr<Solution> rsolution;
};
