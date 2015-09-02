#include "om_random_permutation_generation.h"
#include "strategy/random_permutation_configuration_strategy.h"

#include <iostream>

OM_RandomPermutationGeneration::OM_RandomPermutationGeneration()
{
}

Solution * OM_RandomPermutationGeneration::spcf_execute(PSP *psp, Solution * input)
{
    RandomPermutationConfigurationStrategy * rconf = new RandomPermutationConfigurationStrategy();
    Solution * rsolution = rconf->generate(psp->GetBenchmark()->Domains());
    psp->UpdateSolution(rsolution);
    return rsolution;
}

string OM_RandomPermutationGeneration::codeToSend()
{
    return "A6";
}
