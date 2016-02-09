#include "om_golfers_single_week_adaptive_search_neighborhood.h"
#include "../tools/tools.h"
#include "../tools/tokens_definition.h"

#include <iostream>
using namespace std;

OM_GolfersSingleWeekAdaptiveSearchNeighborhood::OM_GolfersSingleWeekAdaptiveSearchNeighborhood(shared_ptr<Benchmark> bench, int _zero_based_week)
    : object_bench(static_pointer_cast<Golfers> (bench)),
      V(make_shared<GolfersAdaptiveSearchSingleWeekNeighborhood>(object_bench, bench->Domains().size(), object_bench->PlayersPerGroup(), object_bench->Groups(), _zero_based_week))
{}

shared_ptr<Neighborhood> OM_GolfersSingleWeekAdaptiveSearchNeighborhood::spcf_execute(shared_ptr<PSP>, shared_ptr<Solution> input)
{
    V->Init(input->GetConfiguration());
    //cout << "OM_V" << endl;
    return V;
}

string OM_GolfersSingleWeekAdaptiveSearchNeighborhood::codeToSend()
{
    return OM_GOLFERS_SINGLE_WEEK_ADAPTIVE_SEARCH_NEIGHBORHOOD_TOK;
}

string OM_GolfersSingleWeekAdaptiveSearchNeighborhood::Tag()
{
    return "(N)Golfers_SingleWeekASSwap";
}
