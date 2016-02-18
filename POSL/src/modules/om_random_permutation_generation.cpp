#include "om_random_permutation_generation.h"
#include "../tools/tokens_definition.h"
#include "../data/domain.h"

#include <iostream>

using namespace std;

int dmin (Domain d) { return d.minimum(); }
int dmax (Domain d) { return d.maximum(); }

OM_RandomPermutationGeneration::OM_RandomPermutationGeneration(shared_ptr<Benchmark> bench)
    : AOM_FirstConfigurationGeneration(bench),
      rconf_strategy(make_shared<RandomPermutationConfigurationStrategy>(bench->Domains().size())),
      //rconf_strategy(make_shared<RandomPermutationConfigurationStrategy>(dmin(bench->Domains()[0]), dmax(bench->Domains()[0]))),
      rsolution(make_shared<Solution>(bench->Domains()))
{
}

shared_ptr<Solution> OM_RandomPermutationGeneration::spcf_execute(shared_ptr<PSP> psp, std::shared_ptr<Seed> seed)
{
    rsolution->UpdateConfiguration(rconf_strategy->generate(seed));
    psp->Start(rsolution->GetConfiguration());
    //psp->log("Start ");//->" + rsolution->configurationToString());
    //cout << Tag() << endl;
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
