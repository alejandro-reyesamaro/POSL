#include "om_random_conf_ordered_generation.h"
#include "../computation/random_ordered_generation_strategy.h"
#include "../benchmarks/golomb_ruler.h"

#include <random>
#include <iostream>

OM_RandomConfOrderedGeneration::OM_RandomConfOrderedGeneration()
{
}

Solution * OM_RandomConfOrderedGeneration::spcf_execute(PSP *psp, Solution * input)
{
    RandomOrderedGenerationStrategy * rconf = new RandomOrderedGenerationStrategy();
    GolombRuler * object_bench = dynamic_cast<GolombRuler *> (psp->GetBenchmark());
    if(object_bench == NULL)
        throw "(POSL exception) Not casting allowed";
    int max = object_bench->Length();
    int size = object_bench->Order();
    Solution * rsolution = rconf->generate(size, max);
    psp->UpdateSolution(rsolution);
    return rsolution;
}

string OM_RandomConfOrderedGeneration::codeToSend()
{
    return "A5";
}
