#include "om_adaptive_search_range_neighborhood.h"
#include "../tools/tokens_definition.h"

#include <iostream>

using namespace std;

OM_AdaptiveSearchRangeNeighborhood::OM_AdaptiveSearchRangeNeighborhood(shared_ptr<Benchmark> bench, int _a, int _b)
    : V(make_shared<AdaptiveSearchRangeNeighborhood>(bench, _a, _b))
{}

shared_ptr<Neighborhood> OM_AdaptiveSearchRangeNeighborhood::spcf_execute(shared_ptr<PSP> psp, shared_ptr<Solution> input)
{
    V->Init(psp, input->get_conf_by_ref());
    return V;
}


string OM_AdaptiveSearchRangeNeighborhood::codeToSend()
{
    return OM_ADAPTIVE_SEARCH_RANGE_NEIGHBORHOOD_TOK; // "OM_V.ASR"
}

string OM_AdaptiveSearchRangeNeighborhood::Tag()
{
    return "(N)Adaptive_Search_Range";
}
