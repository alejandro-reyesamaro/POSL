#include "om_random_permutation_generation.h"
#include "../tools/tokens_definition.h"

#include <iostream>

using namespace std;

OM_RandomPermutationGeneration::OM_RandomPermutationGeneration(shared_ptr<Benchmark> bench)
    : AOM_FirstConfigurationGeneration(bench),
      rconf_strategy(make_shared<RandomPermutationConfigurationStrategy>(bench->Domains().size())),
      rsolution(make_shared<Solution>(bench->Domains()))
{
}

shared_ptr<Solution> OM_RandomPermutationGeneration::spcf_execute(shared_ptr<PSP> psp, std::shared_ptr<Seed>)
{
    rsolution->UpdateConfiguration(rconf_strategy->generate());
    psp->UpdateSolution(rsolution->GetConfiguration());
    return rsolution;
}

string OM_RandomPermutationGeneration::codeToSend()
{
    return OM_RANDOM_PERMUTATION_GENERATION_TOK;
}

string OM_RandomPermutationGeneration::Tag()
{
    return "Random_Permutation_first";
}
