#include "om_one_sorted_change_neighborhood.h"

#include <iostream>

OM_OneSortedChangeNeighborhood::OM_OneSortedChangeNeighborhood(Benchmark * bench)
    : V(new OneSortedChangeNeighborhood(bench->Domains().size()))
{}

Neighborhood * OM_OneSortedChangeNeighborhood::spcf_execute(PSP * psp, Solution * input)
{
    V->Init(input->GetConfiguration());
    return V;
}

string OM_OneSortedChangeNeighborhood::codeToSend()
{
    return "B5";
}
