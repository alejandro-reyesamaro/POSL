#include "om_golfers_single_swap_neighborhood.h"
#include "../data/golfers_single_swap_neighborhood.h"
#include "../benchmarks/golfers.h"

#include <iostream>
using namespace std;

OM_GolfersSingleSwapNeighborhood::OM_GolfersSingleSwapNeighborhood(){}

ComputationData * OM_GolfersSingleSwapNeighborhood::execute(PSP *psp, ComputationData * input)
{
    //cout << "Inside Neighborhood function" << endl;
    Golfers * s = dynamic_cast<Golfers *>(psp->GetBenchmark());
    if (s == NULL)
        throw "(POSL esception) Not casting allowed";
    Neighborhood * V = new GolfersSingleSwapNeighborhood((Solution *) input, s->TotalPlayers());
    //cout << "Inside Neighborhood function - DONE" << endl;
    return V;
}

string OM_GolfersSingleSwapNeighborhood::codeToSend()
{
    return "B3";
}
