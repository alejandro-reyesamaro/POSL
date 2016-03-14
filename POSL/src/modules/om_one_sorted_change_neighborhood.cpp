#include "om_one_sorted_change_neighborhood.h"
#include "../tools/tokens_definition.h"

#include <iostream>

using namespace std;

OM_OneSortedChangeNeighborhood::OM_OneSortedChangeNeighborhood(shared_ptr<Benchmark> bench)
    : V(make_shared<OneSortedChangeNeighborhood>(bench->Domains().size()))
{}

shared_ptr<Neighborhood> OM_OneSortedChangeNeighborhood::spcf_execute(shared_ptr<PSP> psp, shared_ptr<Solution> input)
{
    V->Init(psp, input->get_conf_by_ref());
    return V;
}

string OM_OneSortedChangeNeighborhood::codeToSend()
{
    return OM_ONE_SORTED_CHANGE_NEIGHBORHOOD_TOK;
}

string OM_OneSortedChangeNeighborhood::Tag()
{
    return "(N)One_Change(sorted)";
}
