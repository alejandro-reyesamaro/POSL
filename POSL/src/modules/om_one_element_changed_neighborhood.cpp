#include "om_one_element_changed_neighborhood.h"

#include <iostream>

OM_OneElementChangedNeighborhood::OM_OneElementChangedNeighborhood(shared_ptr<Benchmark> bench)
    : V(make_shared<OneElementChangedNeighborhood>(bench->Domains().size(), bench->Domains()))
{}

shared_ptr<Neighborhood> OM_OneElementChangedNeighborhood::spcf_execute(shared_ptr<PSP> psp, shared_ptr<Solution> input)
{
    V->Init(input->GetConfiguration());
    return V;
}

string OM_OneElementChangedNeighborhood::codeToSend()
{
    return "B1";
}
