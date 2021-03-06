#include "om_random_conf_permutation_by_blocks_generation.h"
#include "../tools/tokens_definition.h"

#include <random>
#include <iostream>

using namespace std;

OM_RandomConfPermutationByBlocksGeneration::OM_RandomConfPermutationByBlocksGeneration(shared_ptr<Benchmark> bench)
    : AOM_FirstConfigurationGeneration(bench),
      rsolution(make_shared<Solution>(bench->Variable_Domain(), bench->Dimension())),
      object_bench(dynamic_pointer_cast<Golfers> (bench)),
      rconf_strategy(make_shared<RandomPermutationByBlocksGenerationStrategy>(bench->Dimension(), object_bench->TotalPlayers()))
{}

shared_ptr<Solution> OM_RandomConfPermutationByBlocksGeneration::spcf_execute(shared_ptr<PSP> psp, std::shared_ptr<Seed>)
{
    int block_size = object_bench->Groups() * object_bench->PlayersPerGroup();
    int blocks = object_bench->Weeks();

    rsolution->UpdateConfiguration(rconf_strategy->generate(psp->GetRandomizer(), block_size, blocks));
    psp->Start(rsolution->get_conf_by_ref());
    //psp->log("Start ");
    //cout << "OM_S" << endl;
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
