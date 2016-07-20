#include "om_golfers_custom_week_adaptive_search_neighborhood.h"
#include "../tools/tools.h"
#include "../tools/tokens_definition.h"

#include <iostream>
using namespace std;

OM_GolfersCustomWeekAdaptiveSearchNeighborhood::OM_GolfersCustomWeekAdaptiveSearchNeighborhood(shared_ptr<Benchmark> bench,
                                                                                               vector<int> _zero_based_weeks)
    : object_bench(static_pointer_cast<Golfers> (bench)),
      V(make_shared<GolfersAdaptiveSearchCustomWeekNeighborhood>(object_bench,
                                                                 bench->Dimension(),
                                                                 object_bench->PlayersPerGroup(),
                                                                 object_bench->Groups(),
                                                                 _zero_based_weeks))
{}

shared_ptr<Neighborhood> OM_GolfersCustomWeekAdaptiveSearchNeighborhood::spcf_execute(shared_ptr<PSP> psp, shared_ptr<Solution> input)
{
    V->Init(psp, input->get_conf_by_ref());
    //cout << "OM_V" << endl;
    return V;
}

string OM_GolfersCustomWeekAdaptiveSearchNeighborhood::codeToSend()
{
    return OM_GOLFERS_CUSTOM_WEEK_ADAPTIVE_SEARCH_NEIGHBORHOOD_TOK; //"OM_V.CWASGolfers"
}

string OM_GolfersCustomWeekAdaptiveSearchNeighborhood::Tag()
{
    return "(N)Golfers_CustomWeekASSwap";
}
