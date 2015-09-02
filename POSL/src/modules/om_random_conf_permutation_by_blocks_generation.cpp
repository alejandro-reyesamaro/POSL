#include "om_random_conf_permutation_by_blocks_generation.h"


#include <random>
#include <iostream>

OM_RandomConfPermutationByBlocksGeneration::OM_RandomConfPermutationByBlocksGeneration(Benchmark * bench)
    : AOM_FirstConfigurationGeneration(bench),
      rsolution(new Solution(bench->Domains())),
      object_bench(dynamic_cast<Golfers *> (bench)),
      rconf_strategy(new RandomPermutationByBlocksGenerationStrategy(bench->Domains().size(), object_bench->TotalPlayers()))
{
}

Solution * OM_RandomConfPermutationByBlocksGeneration::spcf_execute(PSP *psp, Solution * input)
{
    int block_size = object_bench->Groups() * object_bench->PlayersPerGroup();
    int blocks = object_bench->Weeks();
    rsolution->UpdateConfiguration(rconf_strategy->generate(block_size, blocks));
    psp->UpdateSolution(rsolution);
    return rsolution;
}

string OM_RandomConfPermutationByBlocksGeneration::codeToSend()
{
    return "A4";
}
