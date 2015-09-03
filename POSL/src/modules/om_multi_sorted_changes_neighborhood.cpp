#include "om_multi_sorted_changes_neighborhood.h"

#include <iostream>

OM_MultiSortedChangesNeighborhood::OM_MultiSortedChangesNeighborhood(Benchmark * bench)
    : V(new MultiSortedChangesNeighborhood(bench->Domains().size(), bench->Domains()))
{}

Neighborhood * OM_MultiSortedChangesNeighborhood::spcf_execute(PSP * psp, Solution * input)
{
    V->Init(input->GetConfiguration());
    return V;
}

string OM_MultiSortedChangesNeighborhood::codeToSend()
{
    return "B4";
}
