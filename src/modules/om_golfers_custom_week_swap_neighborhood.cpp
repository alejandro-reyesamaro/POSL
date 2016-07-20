#include "om_golfers_custom_week_swap_neighborhood.h"
#include "../tools/tools.h"
#include "../tools/tokens_definition.h"

#include <iostream>
using namespace std;

OM_GolfersCustomWeekSwapNeighborhood::OM_GolfersCustomWeekSwapNeighborhood(shared_ptr<Benchmark> bench, vector<int> _zero_based_weeks)
    : object_bench(static_pointer_cast<Golfers> (bench)),
      V(make_shared<GolfersCustomWeekSwapNeighborhood>(bench->Dimension(),
                                                       object_bench->PlayersPerGroup(),
                                                       object_bench->Groups(),
                                                       _zero_based_weeks))
{}

shared_ptr<Neighborhood> OM_GolfersCustomWeekSwapNeighborhood::spcf_execute(shared_ptr<PSP> psp, shared_ptr<Solution> input)
{
    V->Init(psp, input->get_conf_by_ref());
    //cout << "OM_V" << endl;
    return V;
}

string OM_GolfersCustomWeekSwapNeighborhood::codeToSend()
{
    return OM_GOLFERS_CUSTOM_WEEK_SWAP_NEIGHBORHOOD_TOK; // "OM_V.CWSwapBtwnBlocks"
}

string OM_GolfersCustomWeekSwapNeighborhood::Tag()
{
    return "(N)Golfers_CustomWeekSwap";
}
