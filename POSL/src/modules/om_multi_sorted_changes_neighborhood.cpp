#include "om_multi_sorted_changes_neighborhood.h"

#include <iostream>

OM_MultiSortedChangesNeighborhood::OM_MultiSortedChangesNeighborhood(shared_ptr<Benchmark> bench)
    : V(make_shared<MultiSortedChangesNeighborhood>(bench->Domains().size(), bench->Domains()))
{}

shared_ptr<Neighborhood> OM_MultiSortedChangesNeighborhood::spcf_execute(shared_ptr<PSP> psp, shared_ptr<Solution> input)
{
    V->Init(input->GetConfiguration());
    return V;
}

string OM_MultiSortedChangesNeighborhood::codeToSend()
{
    return "B4";
}
