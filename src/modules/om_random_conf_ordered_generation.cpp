#include "om_random_conf_ordered_generation.h"
#include "../tools/tokens_definition.h"

#include <random>
#include <iostream>

using namespace std;

OM_RandomConfOrderedGeneration::OM_RandomConfOrderedGeneration(shared_ptr<Benchmark> bench)
    : AOM_FirstConfigurationGeneration(bench),
      rconf_strategy(make_shared<RandomOrderedGenerationStrategy>(bench->Dimension())),
      rsolution(make_shared<Solution>(bench->Variable_Domain(), bench->Dimension())),
      object_bench(dynamic_pointer_cast<GolombRuler> (bench))
{}

shared_ptr<Solution> OM_RandomConfOrderedGeneration::spcf_execute(shared_ptr<PSP> psp, std::shared_ptr<Seed>)
{
    if(!object_bench)
        throw "(POSL exception) Not casting allowed (OM_RandomConfOrderedGeneration.spfc_execute)";
    int max = object_bench->Length();
    rsolution->UpdateConfiguration(rconf_strategy->generate(psp->GetRandomizer(), max));
    psp->Start(rsolution->get_conf_by_ref());
    return rsolution;
}

string OM_RandomConfOrderedGeneration::codeToSend()
{
    return OM_RANDOM_CONFIG_ORDERED_GENERATION_TOCK;
}

string OM_RandomConfOrderedGeneration::Tag()
{
    return "Random_first(sorted)";
}
