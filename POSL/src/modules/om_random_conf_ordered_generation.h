#pragma once

#include "aom_first_configuration_generation.h"
#include "../data/solution.h"
#include "../benchmarks/benchmark.h"
#include "strategy/random_ordered_generation_strategy.h"
#include "../benchmarks/golomb_ruler.h"

class OM_RandomConfOrderedGeneration : public AOM_FirstConfigurationGeneration
{
    public:
        OM_RandomConfOrderedGeneration(Benchmark * bench);

        //! Execute the O.M.
        /*!
        * \brief The input is a configuration, but in this case is not tacken into account
        * \param psp The Problem Search Process
        * \param input Input (configuration)
        * \return A random configuration/permutation-by-blocks
        */
        Solution * spcf_execute(PSP * psp, Solution * input);

        //! From Codable
        string codeToSend();

    private:
        RandomOrderedGenerationStrategy * rconf_strategy;
        Solution * rsolution;
        GolombRuler * object_bench;
};
