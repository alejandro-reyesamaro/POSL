#include "om_random_permutation_generation.h"

#include <iostream>

OM_RandomPermutationGeneration::OM_RandomPermutationGeneration(shared_ptr<Benchmark> bench)
    : AOM_FirstConfigurationGeneration(bench),
      rconf_strategy(make_shared<RandomPermutationConfigurationStrategy>(bench->Domains().size())),
      rsolution(make_shared<Solution>(bench->Domains()))
{
}

shared_ptr<Solution> OM_RandomPermutationGeneration::spcf_execute(shared_ptr<PSP> psp, shared_ptr<Solution> input)
{
    rsolution->UpdateConfiguration(rconf_strategy->generate());
    psp->UpdateSolution(rsolution);
    return rsolution;
}

string OM_RandomPermutationGeneration::codeToSend()
{
    return "A6";
}
