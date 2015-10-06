#include "om_random_permutation_generation.h"

#include <iostream>

using namespace std;

OM_RandomPermutationGeneration::OM_RandomPermutationGeneration(shared_ptr<Benchmark> bench)
    : AOM_FirstConfigurationGeneration(bench),
      rconf_strategy(make_shared<RandomPermutationConfigurationStrategy>(bench->Domains().size())),
      rsolution(make_shared<Solution>(bench->Domains()))
{
}

shared_ptr<Solution> OM_RandomPermutationGeneration::spcf_execute(shared_ptr<PSP> psp, shared_ptr<Solution> input)
{
    rsolution->UpdateConfiguration(rconf_strategy->generate());
    psp->UpdateSolution(rsolution->GetConfiguration());
    return rsolution;
}

string OM_RandomPermutationGeneration::codeToSend()
{
    return "A6";
}

string OM_RandomPermutationGeneration::Tag()
{
    return "Random_Permutation_first";
}
