#include "om_multi_elements_changed_neighborhood.h"

#include <iostream>

OM_MultiElementsChangedNeighborhood::OM_MultiElementsChangedNeighborhood(Benchmark * bench)
    : V(new MultiElementsChangedNeighborhood(bench->Domains().size(), bench->Domains()))
{}

Neighborhood * OM_MultiElementsChangedNeighborhood::spcf_execute(PSP * psp, Solution * input)
{
    V->Init(input->GetConfiguration());
    return V;
}

string OM_MultiElementsChangedNeighborhood::codeToSend()
{
    return "B2";
}
