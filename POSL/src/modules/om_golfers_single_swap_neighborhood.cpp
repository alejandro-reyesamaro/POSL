#include "om_golfers_single_swap_neighborhood.h"
#include "../data/golfers_single_swap_neighborhood.h"
#include "../benchmarks/golfers.h"

#include <iostream>
using namespace std;

OM_GolfersSingleSwapNeighborhood::OM_GolfersSingleSwapNeighborhood(){}

Neighborhood * OM_GolfersSingleSwapNeighborhood::spcf_execute(PSP * psp, Solution * input)
{
    Golfers * s = dynamic_cast<Golfers *>(psp->GetBenchmark());
    if (s == NULL)
        throw "(POSL esception) Not casting allowed";
    Neighborhood * V = new GolfersSingleSwapNeighborhood(input, s->TotalPlayers());
    return V;
}

string OM_GolfersSingleSwapNeighborhood::codeToSend()
{
    return "B3";
}
