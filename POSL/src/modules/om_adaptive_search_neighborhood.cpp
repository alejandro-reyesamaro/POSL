#include "om_adaptive_search_neighborhood.h"
#include "../tools/tokens_definition.h"

#include <iostream>

using namespace std;

OM_AdaptiveSearchNeighborhood::OM_AdaptiveSearchNeighborhood(shared_ptr<Benchmark> bench)
    : V(make_shared<AdaptiveSearchNeighborhood>(bench))
{}

shared_ptr<Neighborhood> OM_AdaptiveSearchNeighborhood::spcf_execute(shared_ptr<PSP> psp, shared_ptr<Solution> input)
{
    V->Init(psp, input->get_conf_by_ref());
    //psp->log("Executing neighborhood function...");
    return V;
}

string OM_AdaptiveSearchNeighborhood::codeToSend()
{
    return OM_ADAPTIVE_SEARCH_NEIGHBORHOOD_TOK;
}

string OM_AdaptiveSearchNeighborhood::Tag()
{
    return "(N)Adaptive_Search";
}
