#include "om_random_conf_permutation_by_blocks_generation.h"
#include "../computation/random_permutation_by_blocks_generation_strategy.h"
#include "../benchmarks/golfers.h"

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
    Golfers * object_bench = dynamic_cast<Golfers *> (psp->GetBenchmark());
    if(object_bench == NULL)
        throw "(POSL exception) Not casting allowed";
    int block_size = object_bench->Groups() * object_bench->PlayersPerGroup();
    int blocks = object_bench->Weeks();
    Solution * rsolution = rconf->generate(block_size, blocks);
    psp->UpdateSolution(rsolution);
    return rsolution;
}

string OM_RandomConfPermutationByBlocksGeneration::codeToSend()
{
    return "A4";
}
