#pragma once

#include "operation_module.h"
#include "aom_first_configuration_generation.h"
#include "../data/solution.h"
#include "../benchmarks/benchmark.h"
#include "strategy/random_permutation_configuration_strategy.h"

class OM_RandomPermutationGeneration : public AOM_FirstConfigurationGeneration
{
    public:
        OM_RandomPermutationGeneration(shared_ptr<Benchmark> bench);

        shared_ptr<Solution> spcf_execute(shared_ptr<PSP> psp, shared_ptr<Solution> input);


        //! From Codable
        string codeToSend();

    private:
        shared_ptr<RandomPermutationConfigurationStrategy> rconf_strategy;
        shared_ptr<Solution> rsolution;
};
