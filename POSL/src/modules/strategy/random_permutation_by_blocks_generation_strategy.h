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

//#include <random>

/*!
 * \class RandomPermutationByBlocksGenerationStrategy random_permutation_by_blocks_generation_strategy.h
 * \brief Class to generate random configurations (Solutions) but a permutation by blocks
 */
class RandomPermutationByBlocksGenerationStrategy
{
    public:
        RandomPermutationByBlocksGenerationStrategy(int configuration_size, int block_size);

        std::vector<int> generate(int block_size, int n_blocks);

    private:
        std::vector<int> config;
        std::vector<int> permutations;
};
