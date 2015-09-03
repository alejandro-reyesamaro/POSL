#include "om_golfers_single_swap_neighborhood.h"

#include <iostream>
using namespace std;

OM_GolfersSingleSwapNeighborhood::OM_GolfersSingleSwapNeighborhood(Benchmark * bench)
    : object_bench(dynamic_cast<Golfers *> (bench)),
      V(new GolfersSingleSwapNeighborhood(bench->Domains().size(), object_bench->TotalPlayers()))
{}

Neighborhood * OM_GolfersSingleSwapNeighborhood::spcf_execute(PSP * psp, Solution * input)
{
    V->Init(input->GetConfiguration());
    return V;
}

string OM_GolfersSingleSwapNeighborhood::codeToSend()
{
    return "B3";
}
