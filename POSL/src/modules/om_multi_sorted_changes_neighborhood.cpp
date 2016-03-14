#include "om_multi_sorted_changes_neighborhood.h"
#include "../tools/tokens_definition.h"

#include <iostream>

using namespace std;

OM_MultiSortedChangesNeighborhood::OM_MultiSortedChangesNeighborhood(shared_ptr<Benchmark> bench)
    : V(make_shared<MultiSortedChangesNeighborhood>(bench->Domains().size(), bench->Domains()))
{}

shared_ptr<Neighborhood> OM_MultiSortedChangesNeighborhood::spcf_execute(shared_ptr<PSP> psp, shared_ptr<Solution> input)
{
    V->Init(psp, input->get_conf_by_ref());
    return V;
}

string OM_MultiSortedChangesNeighborhood::codeToSend()
{
    return OM_MULTI_SORTED_CHANGES_NEIGHBORHOOD_TOK;
}

string OM_MultiSortedChangesNeighborhood::Tag()
{
    return "(N)Multi_Changes(sorted)";
}
