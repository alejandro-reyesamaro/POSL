#include "om_random_conf_generation.h"
#include "computation/random_configuration_generation_strategy.h"

#include <random>
#include <iostream>

OM_RandomConfGeneration::OM_RandomConfGeneration()
{
}

ComputationData * OM_RandomConfGeneration::execute(PSP *psp, ComputationData * input)
{
    RandomConfigurationGenerationStrategy * rconf = new RandomConfigurationGenerationStrategy();
    Solution * rsolution = rconf->generate(psp->GetCurrentSolution()->domains, new Seed());
    psp->UpdateSolution(rsolution);
    return rsolution;
}
