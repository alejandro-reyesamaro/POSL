#include "om_random_conf_ordered_generation.h"
#include <random>
#include <iostream>

using namespace std;

OM_RandomConfOrderedGeneration::OM_RandomConfOrderedGeneration(shared_ptr<Benchmark> bench)
    : AOM_FirstConfigurationGeneration(bench),
      rconf_strategy(make_shared<RandomOrderedGenerationStrategy>(bench->Domains().size())),
      rsolution(make_shared<Solution>(bench->Domains())),
      object_bench(dynamic_pointer_cast<GolombRuler> (bench))
{
}

shared_ptr<Solution> OM_RandomConfOrderedGeneration::spcf_execute(shared_ptr<PSP> psp, shared_ptr<Solution> input)
{
    if(!object_bench)
        throw "(POSL exception) Not casting allowed (OM_RandomConfOrderedGeneration.spfc_execute)";
    int max = object_bench->Length();
    //int size = object_bench->Order();
    rsolution->UpdateConfiguration(rconf_strategy->generate(max));
    psp->UpdateSolution(rsolution->GetConfiguration());
    return rsolution;
}

string OM_RandomConfOrderedGeneration::codeToSend()
{
    return "A5";
}

string OM_RandomConfOrderedGeneration::TAG()
{
    return "Random_first(sorted)";
}
