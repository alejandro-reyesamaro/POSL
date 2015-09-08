#pragma once

#include "aom_first_configuration_generation.h"
#include "../data/solution.h"
#include "../benchmarks/benchmark.h"
#include "strategy/random_ordered_generation_strategy.h"
#include "../benchmarks/golomb_ruler.h"

class OM_RandomConfOrderedGeneration : public AOM_FirstConfigurationGeneration
{
    public:
        OM_RandomConfOrderedGeneration(shared_ptr<Benchmark> bench);

        shared_ptr<Solution> spcf_execute(shared_ptr<PSP> psp, shared_ptr<Solution> input);

        //! From Codable
        string codeToSend();

    private:
        shared_ptr<RandomOrderedGenerationStrategy> rconf_strategy;
        shared_ptr<Solution> rsolution;
        shared_ptr<GolombRuler> object_bench;
};
