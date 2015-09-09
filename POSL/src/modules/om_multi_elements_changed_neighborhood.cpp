#include "om_multi_elements_changed_neighborhood.h"

#include <iostream>

using namespace std;

OM_MultiElementsChangedNeighborhood::OM_MultiElementsChangedNeighborhood(shared_ptr<Benchmark> bench)
    : V(make_shared<MultiElementsChangedNeighborhood>(bench->Domains().size(), bench->Domains()))
{}

shared_ptr<Neighborhood> OM_MultiElementsChangedNeighborhood::spcf_execute(shared_ptr<PSP> psp, shared_ptr<Solution> input)
{
    V->Init(input->GetConfiguration());
    return V;
}

string OM_MultiElementsChangedNeighborhood::codeToSend()
{
    return "B2";
}
