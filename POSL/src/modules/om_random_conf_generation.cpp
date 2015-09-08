#include "om_random_conf_generation.h"

#include <random>
#include <iostream>

OM_RandomConfGeneration::OM_RandomConfGeneration(shared_ptr<Benchmark> bench)
    : AOM_FirstConfigurationGeneration(bench),
      rconf_strategy(new RandomConfigurationGenerationStrategy(bench->Domains().size())),
      rsolution(new Solution(bench->Domains()))
{}

shared_ptr<Solution> OM_RandomConfGeneration::spcf_execute(shared_ptr<PSP> psp, shared_ptr<Solution> input)
{
    rsolution->UpdateConfiguration(rconf_strategy->generate(domains));
    psp->UpdateSolution(rsolution);
    return rsolution;
}

string OM_RandomConfGeneration::codeToSend()
{
    return "A2";
}
