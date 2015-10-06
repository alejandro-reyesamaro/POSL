#pragma once

#include "aom_first_configuration_generation.h"
#include "../data/solution.h"
#include "../benchmarks/benchmark.h"
#include "strategy/random_ordered_generation_strategy.h"
#include "../benchmarks/golomb_ruler.h"

class OM_RandomConfOrderedGeneration : public AOM_FirstConfigurationGeneration
{
    public:
        OM_RandomConfOrderedGeneration(std::shared_ptr<Benchmark> bench);

        std::shared_ptr<Solution> spcf_execute(std::shared_ptr<PSP> psp, std::shared_ptr<Solution> input);

        //! From Codable
        std::string codeToSend();

        virtual std::string Tag();

    protected:
        std::shared_ptr<RandomOrderedGenerationStrategy> rconf_strategy;
        std::shared_ptr<Solution> rsolution;
        std::shared_ptr<GolombRuler> object_bench;
};
