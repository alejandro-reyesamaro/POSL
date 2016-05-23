#include "om_random_conf_generation.h"
#include "../tools/tokens_definition.h"

#include <random>
#include <iostream>

using namespace std;

OM_RandomConfGeneration::OM_RandomConfGeneration(shared_ptr<Benchmark> bench)
    : AOM_FirstConfigurationGeneration(bench),
      rconf_strategy(std::make_shared<RandomConfigurationGenerationStrategy>(bench->Dimension())),
      rsolution(std::make_shared<Solution>(bench->Variable_Domain(), bench->Dimension()))
{}

shared_ptr<Solution> OM_RandomConfGeneration::spcf_execute(shared_ptr<PSP> psp, std::shared_ptr<Seed>)
{
    rsolution->UpdateConfiguration(rconf_strategy->generate(psp->GetRandomizer(), domain));
    psp->Start(rsolution->get_conf_by_ref());
    return rsolution;
}

string OM_RandomConfGeneration::codeToSend()
{
    return OM_RANDOM_CONFIG_GENERATION_TOK;
}

string OM_RandomConfGeneration::Tag()
{
    return "Random_first";
}
