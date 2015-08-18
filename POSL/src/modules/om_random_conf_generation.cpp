#include "om_random_conf_generation.h"
#include "../computation/random_configuration_generation_strategy.h"

#include <random>
#include <iostream>

OM_RandomConfGeneration::OM_RandomConfGeneration()
{
}

//ComputationData * OM_RandomConfGeneration::execute(PSP *psp, ComputationData * input)
Solution * OM_RandomConfGeneration::spcf_execute(PSP *psp, Solution * input)
{
    RandomConfigurationGenerationStrategy * rconf = new RandomConfigurationGenerationStrategy();
    Solution * rsolution = rconf->generate(psp->GetBenchmark()->Domains());
    psp->UpdateSolution(rsolution);
    return rsolution;
}

string OM_RandomConfGeneration::codeToSend()
{
    return "A2";
}
