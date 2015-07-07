#include "om_random_conf_permutation_by_blocks_generation.h"
#include "computation/random_permutation_by_blocks_generation_strategy.h"

#include <random>
#include <iostream>

#define BLOCK_SIZE 16
#define N_BLOCKS 2

OM_RandomConfPermutationByBlocksGeneration::OM_RandomConfPermutationByBlocksGeneration()
{
}

ComputationData * OM_RandomConfPermutationByBlocksGeneration::execute(PSP *psp, ComputationData * input)
{
    RandomPermutationByBlocksGenerationStrategy * rconf = new RandomPermutationByBlocksGenerationStrategy();
    Solution * rsolution = rconf->generate(BLOCK_SIZE, N_BLOCKS);
    psp->UpdateSolution(rsolution);
    psp->UpdateBestSolution(rsolution);
    return rsolution;
}
