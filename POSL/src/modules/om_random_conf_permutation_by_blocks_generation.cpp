#include "om_random_conf_permutation_by_blocks_generation.h"

#include <random>
#include <iostream>

using namespace std;

OM_RandomConfPermutationByBlocksGeneration::OM_RandomConfPermutationByBlocksGeneration(shared_ptr<Benchmark> bench)
    : AOM_FirstConfigurationGeneration(bench),
      rsolution(make_shared<Solution>(bench->Domains())),
      object_bench(dynamic_pointer_cast<Golfers> (bench)),
      rconf_strategy(make_shared<RandomPermutationByBlocksGenerationStrategy>(bench->Domains().size(), object_bench->TotalPlayers()))
{}

shared_ptr<Solution> OM_RandomConfPermutationByBlocksGeneration::spcf_execute(shared_ptr<PSP> psp, std::shared_ptr<Seed>)
{
    int block_size = object_bench->Groups() * object_bench->PlayersPerGroup();
    int blocks = object_bench->Weeks();

    rsolution->UpdateConfiguration(rconf_strategy->generate(block_size, blocks));
    //cout << rsolution->configurationToString() << endl;
    //psp->UpdateSolution(rsolution->GetConfiguration());
    psp->Start(rsolution->GetConfiguration());
    return rsolution;
}

string OM_RandomConfPermutationByBlocksGeneration::codeToSend()
{
    return OM_RANDOM_CONFIG_PERMUTATION_BY_BLOCKS_TOK;
}

string OM_RandomConfPermutationByBlocksGeneration::Tag()
{
    return "Golfers_first";
}
