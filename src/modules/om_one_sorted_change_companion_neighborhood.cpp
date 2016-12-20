#include "om_one_sorted_change_companion_neighborhood.h"
#include "../tools/tokens_definition.h"

#include <iostream>

using namespace std;

OM_OneSortedChangeCompanionNeighborhood::OM_OneSortedChangeCompanionNeighborhood(shared_ptr<Benchmark> bench)
    : V(make_shared<OneSortedChangeCompanionNeighborhood>(bench->Dimension()))
{}

shared_ptr<Neighborhood> OM_OneSortedChangeCompanionNeighborhood::spcf_execute(shared_ptr<PSP> psp, shared_ptr<Solution> input)
{
    V->Init(psp, input->get_conf_by_ref());
    return V;
}

string OM_OneSortedChangeCompanionNeighborhood::codeToSend()
{
    return OM_ONE_SORTED_CHANGE_COMPANION_NEIGHBORHOOD_TOK;
}

string OM_OneSortedChangeCompanionNeighborhood::Tag()
{
    return "(N)One_Change(sorted-companion)";
}
