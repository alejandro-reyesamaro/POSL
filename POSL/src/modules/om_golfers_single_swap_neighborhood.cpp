#include "om_golfers_single_swap_neighborhood.h"
#include "../tools/tools.h"
#include "../tools/tokens_definition.h"

#include <iostream>
using namespace std;

OM_GolfersSingleSwapNeighborhood::OM_GolfersSingleSwapNeighborhood(shared_ptr<Benchmark> bench)
    : object_bench(static_pointer_cast<Golfers> (bench)),
      V(make_shared<GolfersSingleSwapNeighborhood>(bench->Domains().size(), object_bench->PlayersPerGroup(), object_bench->Groups()))
{}

shared_ptr<Neighborhood> OM_GolfersSingleSwapNeighborhood::spcf_execute(shared_ptr<PSP> psp, shared_ptr<Solution> input)
{
    V->Init(psp, input->get_conf_by_ref());
    //cout << "OM_V" << endl;
    return V;
}

string OM_GolfersSingleSwapNeighborhood::codeToSend()
{
    return OM_GOLFERS_SINGLE_SWAP_NEIGHBORHOOD_TOK;
}

string OM_GolfersSingleSwapNeighborhood::Tag()
{
    return "(N)Golfers_SingleSwap";
}
