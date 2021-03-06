#include "om_random_permutation_generation.h"
#include "../tools/tokens_definition.h"
#include "../data/domain.h"

#include <iostream>

using namespace std;

OM_RandomPermutationGeneration::OM_RandomPermutationGeneration(shared_ptr<Benchmark> bench)
    : AOM_FirstConfigurationGeneration(bench),
      //rconf_strategy(make_shared<RandomPermutationConfigurationStrategy>(bench->Domains().size())),
      rconf_strategy(make_shared<RandomPermutationConfigurationStrategy>(bench->Variable_Domain()->minimum(0),
                                                                         bench->Variable_Domain()->maximum(0))),
      rsolution(make_shared<Solution>(bench->Variable_Domain(), bench->Dimension()))
{}

shared_ptr<Solution> OM_RandomPermutationGeneration::spcf_execute(shared_ptr<PSP> psp, std::shared_ptr<Seed>)
{
    rsolution->UpdateConfiguration(rconf_strategy->generate(psp->GetRandomizer()));
    psp->Start(rsolution->get_conf_by_ref());
    //psp->log("Start ");//->" + rsolution->configurationToString());
    //cout << psp->GetPID() << ": " << Tag() << endl;
    return rsolution;
}

string OM_RandomPermutationGeneration::codeToSend()
{
    return OM_RANDOM_PERMUTATION_GENERATION_TOK;
}

string OM_RandomPermutationGeneration::Tag()
{
    return "Random_Permutation_first";
}
