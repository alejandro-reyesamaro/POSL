#include "om_random_conf_generation.h"

#include <random>
#include <iostream>

OM_RandomConfGeneration::OM_RandomConfGeneration(vector<Domain> _domains)
    : AOM_FirstConfigurationGeneration(_domains),
      rconf_strategy(new RandomConfigurationGenerationStrategy(_domains.size())),
      rsolution(new Solution(_domains))
{}

Solution * OM_RandomConfGeneration::spcf_execute(PSP *psp, Solution * input)
{
    rsolution->UpdateConfiguration(rconf_strategy->generate(domains));
    psp->UpdateSolution(rsolution);
    return rsolution;
}

string OM_RandomConfGeneration::codeToSend()
{
    return "A2";
}
