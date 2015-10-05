#include "om_one_element_changed_neighborhood.h"

#include <iostream>

using namespace std;

OM_OneElementChangedNeighborhood::OM_OneElementChangedNeighborhood(shared_ptr<Benchmark> bench)
    : V(std::make_shared<OneElementChangedNeighborhood>(bench->Domains().size(), bench->Domains()))
{}

shared_ptr<Neighborhood> OM_OneElementChangedNeighborhood::spcf_execute(shared_ptr<PSP> psp, std::shared_ptr<Solution> input)
{
    V->Init(input->GetConfiguration());
    return V;
}

string OM_OneElementChangedNeighborhood::codeToSend()
{
    return "B1";
}

string OM_OneElementChangedNeighborhood::TAG()
{
    return "(N)One_Change";
}
