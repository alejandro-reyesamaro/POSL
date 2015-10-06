#include "random_permutation_by_blocks_generation_strategy.h"
#include "../../data/dStrategy/factory_n_int_domain.h"
#include "../../tools/tools.h"

#include <algorithm>
#include <iostream>

using namespace std;

RandomPermutationByBlocksGenerationStrategy::RandomPermutationByBlocksGenerationStrategy(int configuration_size, int block_size)
    :config(configuration_size),
      permutations(Tools::generateMonotony(1,block_size))
{}

std::vector<int> RandomPermutationByBlocksGenerationStrategy::generate(int block_size, int n_blocks)
{
    for(int i = 0; i < n_blocks; i++)
    {
        Tools::shuffle(permutations);
        copy(permutations.begin(), permutations.end(), config.begin() + i * block_size);
    }
    return config;
}
