#include "om_random_conf_ordered_generation.h"
#include <random>
#include <iostream>

OM_RandomConfOrderedGeneration::OM_RandomConfOrderedGeneration(Benchmark * bench)
    : AOM_FirstConfigurationGeneration(bench),
      rconf_strategy(new RandomOrderedGenerationStrategy(bench->Domains().size())),
      rsolution(new Solution(bench->Domains())),
      object_bench(dynamic_cast<GolombRuler *> (bench))
{
}

Solution * OM_RandomConfOrderedGeneration::spcf_execute(PSP *psp, Solution * input)
{
    if(!object_bench)
        throw "(POSL exception) Not casting allowed (OM_RandomConfOrderedGeneration.spfc_execute)";
    int max = object_bench->Length();
    //int size = object_bench->Order();
    rsolution->UpdateConfiguration(rconf_strategy->generate(max));
    psp->UpdateSolution(rsolution);
    return rsolution;
}

string OM_RandomConfOrderedGeneration::codeToSend()
{
    return "A5";
}
