#include "om_golfers_single_swap_neighborhood.h"

#include <iostream>
using namespace std;

OM_GolfersSingleSwapNeighborhood::OM_GolfersSingleSwapNeighborhood(shared_ptr<Benchmark> bench)
    : object_bench(static_pointer_cast<Golfers> (bench)),
      V(make_shared<GolfersSingleSwapNeighborhood>(bench->Domains().size(), object_bench->TotalPlayers()))
{}

shared_ptr<Neighborhood> OM_GolfersSingleSwapNeighborhood::spcf_execute(shared_ptr<PSP> psp, shared_ptr<Solution> input)
{
    V->Init(input->GetConfiguration());
    return V;
}

string OM_GolfersSingleSwapNeighborhood::codeToSend()
{
    return "B3";
}
