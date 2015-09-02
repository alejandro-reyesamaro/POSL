#include "om_random_permutation_generation.h"

#include <iostream>

OM_RandomPermutationGeneration::OM_RandomPermutationGeneration(Benchmark * bench)
    : AOM_FirstConfigurationGeneration(bench),
      rconf_strategy(new RandomPermutationConfigurationStrategy(bench->Domains().size())),
      rsolution(new Solution(bench->Domains()))
{
}

Solution * OM_RandomPermutationGeneration::spcf_execute(PSP *psp, Solution * input)
{
    rsolution->UpdateConfiguration(rconf_strategy->generate());
    psp->UpdateSolution(rsolution);
    return rsolution;
}

string OM_RandomPermutationGeneration::codeToSend()
{
    return "A6";
}
