#include "om_adaptive_search_partial_neighborhood.h"
#include "../tools/tokens_definition.h"

#include <iostream>

using namespace std;

OM_AdaptiveSearchPartialNeighborhood::OM_AdaptiveSearchPartialNeighborhood(shared_ptr<Benchmark> bench, int _part)
    : V(make_shared<AdaptiveSearchPartialNeighborhood>(bench, _part))
{}

shared_ptr<Neighborhood> OM_AdaptiveSearchPartialNeighborhood::spcf_execute(shared_ptr<PSP> psp, shared_ptr<Solution> input)
{
    V->Init(psp, input->get_conf_by_ref());
    return V;
}


string OM_AdaptiveSearchPartialNeighborhood::codeToSend()
{
    return OM_ADAPTIVE_SEARCH_PARTIAL_NEIGHBORHOOD_TOK; // "OM_V.ASP"
}

string OM_AdaptiveSearchPartialNeighborhood::Tag()
{
    return "(N)Adaptive_Search_Partial";
}
