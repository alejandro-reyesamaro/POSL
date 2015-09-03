#include "om_one_element_changed_neighborhood.h"

#include <iostream>

OM_OneElementChangedNeighborhood::OM_OneElementChangedNeighborhood(Benchmark * bench)
    : V(new OneElementChangedNeighborhood(bench->Domains().size(), bench->Domains()))
{}

Neighborhood * OM_OneElementChangedNeighborhood::spcf_execute(PSP * psp, Solution * input)
{
    V->Init(input->GetConfiguration());
    return V;
}

string OM_OneElementChangedNeighborhood::codeToSend()
{
    return "B1";
}
