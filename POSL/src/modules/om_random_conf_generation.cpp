#include "om_random_conf_generation.h"

#include <random>
#include <iostream>

using namespace std;

OM_RandomConfGeneration::OM_RandomConfGeneration(shared_ptr<Benchmark> bench)
    : AOM_FirstConfigurationGeneration(bench),
      rconf_strategy(std::make_shared<RandomConfigurationGenerationStrategy>(bench->Domains().size())),
      rsolution(std::make_shared<Solution>(bench->Domains()))
{}

shared_ptr<Solution> OM_RandomConfGeneration::spcf_execute(shared_ptr<PSP> psp, shared_ptr<Solution> input)
{
    rsolution->UpdateConfiguration(rconf_strategy->generate(domains));
    psp->UpdateSolution(rsolution->GetConfiguration());
    return rsolution;
}

string OM_RandomConfGeneration::codeToSend()
{
    return "A2";
}

string OM_RandomConfGeneration::TAG()
{
    return "Random_first";
}
