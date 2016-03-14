#include "om_golfers_single_week_swap_neighborhood.h"
#include "../tools/tools.h"
#include "../tools/tokens_definition.h"

#include <iostream>
using namespace std;

OM_GolfersSingleWeekSwapNeighborhood::OM_GolfersSingleWeekSwapNeighborhood(shared_ptr<Benchmark> bench, int _zero_based_week)
    : object_bench(static_pointer_cast<Golfers> (bench)),
      V(make_shared<GolfersSingleWeekSwapNeighborhood>(bench->Domains().size(), object_bench->PlayersPerGroup(), object_bench->Groups(), _zero_based_week))
{}

shared_ptr<Neighborhood> OM_GolfersSingleWeekSwapNeighborhood::spcf_execute(shared_ptr<PSP> psp, shared_ptr<Solution> input)
{
    V->Init(psp, input->get_conf_by_ref());
    //cout << "OM_V" << endl;
    return V;
}

string OM_GolfersSingleWeekSwapNeighborhood::codeToSend()
{
    return OM_GOLFERS_SINGLE_WEEK_SWAP_NEIGHBORHOOD_TOK;
}

string OM_GolfersSingleWeekSwapNeighborhood::Tag()
{
    return "(N)Golfers_SingleWeekSwap";
}
