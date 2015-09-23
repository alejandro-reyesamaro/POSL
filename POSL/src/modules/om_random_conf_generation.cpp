#include "om_random_conf_generation.h"

#include <random>
#include <iostream>

OM_RandomConfGeneration::OM_RandomConfGeneration(std::shared_ptr<Benchmark> bench)
    : AOM_FirstConfigurationGeneration(bench),
      rconf_strategy(std::make_shared<RandomConfigurationGenerationStrategy>(bench->Domains().size())),
      rsolution(std::make_shared<Solution>(bench->Domains()))
{}

std::shared_ptr<Solution> OM_RandomConfGeneration::spcf_execute(std::shared_ptr<PSP> psp, std::shared_ptr<Solution> input)
{
    rsolution->UpdateConfiguration(rconf_strategy->generate(domains));
    psp->UpdateSolution(rsolution->GetConfiguration());
    return rsolution;
}

std::string OM_RandomConfGeneration::codeToSend()
{
    return "A2";
}
