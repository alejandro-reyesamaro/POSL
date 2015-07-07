#include "random_permutation_by_blocks_generation_strategy.h"
#include "data/factory_n_int_domain.h"

#include <algorithm>

RandomPermutationByBlocksGenerationStrategy::RandomPermutationByBlocksGenerationStrategy() : rand()
{}

Solution * RandomPermutationByBlocksGenerationStrategy::generate(int block_size, int n_blocks)
{
    vector<int> config(block_size * n_blocks);

    for(int i = 0; i < n_blocks; i++)
    {
        vector<int> perm;
        for(int j = 0; j < block_size; j++)
            perm.push_back(j);
        random_shuffle (perm.begin(), perm.end());
        copy(perm.begin(), perm.end(), config.begin() + i * block_size);
    }

    FactoryDomain * fd_integers = new Factory_NIntDomain(1,block_size);
    Domain D(fd_integers);
    vector<Domain> domains (block_size * n_blocks,D);
    Solution * new_solution = new Solution(domains, config);
    return new_solution;
}
