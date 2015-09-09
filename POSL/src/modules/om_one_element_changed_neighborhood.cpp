#include "om_one_element_changed_neighborhood.h"

#include <iostream>

OM_OneElementChangedNeighborhood::OM_OneElementChangedNeighborhood(std::shared_ptr<Benchmark> bench)
    : V(std::make_shared<OneElementChangedNeighborhood>(bench->Domains().size(), bench->Domains()))
{}

std::shared_ptr<Neighborhood> OM_OneElementChangedNeighborhood::spcf_execute(std::shared_ptr<PSP> psp, std::shared_ptr<Solution> input)
{
    V->Init(input->GetConfiguration());
    return V;
}

std::string OM_OneElementChangedNeighborhood::codeToSend()
{
    return "B1";
}
