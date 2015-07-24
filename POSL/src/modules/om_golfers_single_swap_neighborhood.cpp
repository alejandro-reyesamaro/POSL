#include "om_golfers_single_swap_neighborhood.h"
#include "../data/golfers_single_swap_neighborhood.h"
#include "../benchmarks/golfers.h"

#include <iostream>

OM_GolfersSingleSwapNeighborhood::OM_GolfersSingleSwapNeighborhood(){}

ComputationData * OM_GolfersSingleSwapNeighborhood::execute(PSP *psp, ComputationData * input)
{
    // CAMBIAR ??
    Golfers * s = (Golfers *)psp->GetBenchmark();
    Neighborhood * V = new GolfersSingleSwapNeighborhood((Solution *) input, s->TotalPlayers());
    return V;
}

string OM_GolfersSingleSwapNeighborhood::codeToSend()
{
    return "B3";
}
