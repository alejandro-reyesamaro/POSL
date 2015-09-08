#pragma once

/**
 * POSL
 *
 * \file random_permutation_by_blocks_generation_strategy.h
 * \brief Class to generate random configurations (Solutions) but a permutation by blocks
 * \author Alejandro Reyes
 * \date 2015-05-28
 */

#include "../../data/solution.h"
#include "../../data/domain.h"
#include "../../tools/randomizer.h"

#include <random>

/*!
 * \class RandomPermutationByBlocksGenerationStrategy random_permutation_by_blocks_generation_strategy.h
 * \brief Class to generate random configurations (Solutions) but a permutation by blocks
 */
class RandomPermutationByBlocksGenerationStrategy
{
    public:
        RandomPermutationByBlocksGenerationStrategy(int configuration_size, int block_size);

        //! Generates a random configuration
        /*!
        * \param domains The sets of posibles values for the variables
        * \param seed A seed for the random generatos
        * \return A random configuration (Solution) permutation by blocks
        */
        vector<int> generate(int block_size, int n_blocks);

    private:
        //Randomizer rand;
        vector<int> config;
        vector<int> permutations;
};
