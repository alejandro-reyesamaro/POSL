#include "om_random_conf_generation.h"

#include <random>
#include <iostream>

OM_RandomConfGeneration::OM_RandomConfGeneration(Benchmark * bench)
    : AOM_FirstConfigurationGeneration(bench),
      rconf_strategy(new RandomConfigurationGenerationStrategy(bench->Domains().size())),
      rsolution(new Solution(bench->Domains()))
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
