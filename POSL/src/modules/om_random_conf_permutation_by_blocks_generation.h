#pragma once

/**
 * POSL
 *
 * \file om_random_conf_permutation_by_blocks_generation.h
 * \brief Class to represent an Operation module to generate a random first configuration that is a permutation by blocks
 * \author Alejandro Reyes
 * \date 2015-04-14
 */

#include "aom_first_configuration_generation.h"
#include "../data/solution.h"
#include "../benchmarks/benchmark.h"
#include "strategy/random_permutation_by_blocks_generation_strategy.h"
#include "../benchmarks/golfers.h"

/*!
 * \class OM_RandomConfPermutationByBlocksGeneration om_random_conf_permutation_by_blocks_generation.h
 * \brief Class to represent an Operation module to generate a random first configuration that is a permutation by blocks
 */
class OM_RandomConfPermutationByBlocksGeneration : public AOM_FirstConfigurationGeneration
{
    public:
        //! Constructor
        OM_RandomConfPermutationByBlocksGeneration(std::shared_ptr<Benchmark> bench);

        std::shared_ptr<Solution> spcf_execute(std::shared_ptr<PSP> psp, std::shared_ptr<Solution>);

        //! From Codable
        std::string codeToSend();

        virtual std::string Tag();

    protected:
        std::shared_ptr<Solution> rsolution;
        std::shared_ptr<Golfers> object_bench;
        std::shared_ptr<RandomPermutationByBlocksGenerationStrategy> rconf_strategy;

};
