#include "om_one_element_changed_neighborhood.h"
#include "../tools/tokens_definition.h"

#include <iostream>

using namespace std;

OM_OneElementChangedNeighborhood::OM_OneElementChangedNeighborhood(shared_ptr<Benchmark> bench)
    : V(std::make_shared<OneElementChangedNeighborhood>(bench->Dimension(), bench->Variable_Domain()))
{}

shared_ptr<Neighborhood> OM_OneElementChangedNeighborhood::spcf_execute(shared_ptr<PSP> psp, std::shared_ptr<Solution> input)
{
    V->Init(psp, input->get_conf_by_ref());
    return V;
}

string OM_OneElementChangedNeighborhood::codeToSend()
{
    return OM_ONE_CHANGE_NEIHBORHOOD_TOK;
}

string OM_OneElementChangedNeighborhood::Tag()
{
    return "(N)One_Change";
}
