#include "random_permutation_by_blocks_generation_strategy.h"
#include "../../data/dStrategy/factory_n_int_domain.h"
#include "../../tools/tools.h"

#include <algorithm>

RandomPermutationByBlocksGenerationStrategy::RandomPermutationByBlocksGenerationStrategy(int configuration_size, int block_size)
    :config(configuration_size),
      permutations(block_size)
{}

std::vector<int> RandomPermutationByBlocksGenerationStrategy::generate(int block_size, int n_blocks)
{
    for(int i = 0; i < n_blocks; i++)
    {
        for(int j = 0; j < block_size; j++)
            permutations[j]= j+1;
        Tools::shuffle(permutations);
        copy(permutations.begin(), permutations.end(), config.begin() + i * block_size);
    }
    return config;
}
