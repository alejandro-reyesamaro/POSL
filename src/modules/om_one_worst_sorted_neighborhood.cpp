#include "om_one_worst_sorted_neighborhood.h"
#include "../tools/tokens_definition.h"

#include <iostream>

using namespace std;

OM_OneWorstSortedNeighborhood::OM_OneWorstSortedNeighborhood(shared_ptr<Benchmark> bench)
    : V(make_shared<OneWorstSortedChangeNeighborhood>(bench->Dimension(), bench))
{}

shared_ptr<Neighborhood> OM_OneWorstSortedNeighborhood::spcf_execute(shared_ptr<PSP> psp, shared_ptr<Solution> input)
{
    V->Init(psp, input->get_conf_by_ref());
    return V;
}

string OM_OneWorstSortedNeighborhood::codeToSend()
{
    return OM_ONE_WORST_SORTED_CHANGE_NEIGHBORHOOD_TOK;
}

string OM_OneWorstSortedNeighborhood::Tag()
{
    return "(N)One_Worst_Change(sorted)";
}
