#include "om_golfers_adaptive_search_neigborhood.h"
#include "../tools/tools.h"
#include "../tools/tokens_definition.h"

#include <iostream>
using namespace std;

OM_GolfersAdaptiveSearchNeigborhood::OM_GolfersAdaptiveSearchNeigborhood(shared_ptr<Benchmark> bench)
    : object_bench(static_pointer_cast<Golfers> (bench)),
      V(make_shared<GolfersAdaptiveSearchNeighborhood>(object_bench,
                                                       bench->Domains().size(),
                                                       object_bench->PlayersPerGroup(),
                                                       object_bench->Groups()))
{}

shared_ptr<Neighborhood> OM_GolfersAdaptiveSearchNeigborhood::spcf_execute(shared_ptr<PSP>, shared_ptr<Solution> input)
{
    V->Init(input->GetConfiguration());
    return V;
}

string OM_GolfersAdaptiveSearchNeigborhood::codeToSend()
{
    return OM_GOLFERS_ADAPTIVE_SEARCH_NEIGHBORHOOD_TOK;
}

string OM_GolfersAdaptiveSearchNeigborhood::Tag()
{
    return "(N)Golfers_AdaptiveSearch";
}
