#include "om_one_sorted_change_neighborhood.h"

#include <iostream>

using namespace std;

OM_OneSortedChangeNeighborhood::OM_OneSortedChangeNeighborhood(shared_ptr<Benchmark> bench)
    : V(make_shared<OneSortedChangeNeighborhood>(bench->Domains().size()))
{}

shared_ptr<Neighborhood> OM_OneSortedChangeNeighborhood::spcf_execute(shared_ptr<PSP> psp, shared_ptr<Solution> input)
{
    V->Init(input->GetConfiguration());
    return V;
}

string OM_OneSortedChangeNeighborhood::codeToSend()
{
    return "B5";
}
