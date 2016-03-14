#include "neighbor_selecting_best_improvement.h"

#include <iostream>

using namespace std;

NeighborSelectingBestImprovement::NeighborSelectingBestImprovement(vector<Domain> domains)
    : rPair(make_shared<DecisionPair>(make_shared<Solution>(domains), make_shared<Solution>(domains)))
{}

shared_ptr<DecisionPair> NeighborSelectingBestImprovement::select(shared_ptr<PSP> psp, shared_ptr<Neighborhood> V)
{
    current_config = psp->GetCurrentSolution()->get_conf_by_copy();
    int current_cost = psp->CurrentCost();
    best_found_config = psp->GetCurrentSolution()->get_conf_by_copy();
    int best_found_cost = current_cost;
    int c;

    it = V->getIterator();
    it->Reset();

    while(it->SomeNext())
    {
        neighbor = it->GetNext();
        c = psp->GetBenchmark()->relativeSolutionCost(neighbor);
        if(c < best_found_cost)
        {
            best_found_cost   = c;
            best_found_config = neighbor;
        }
    }
    rPair->update(current_config, best_found_config);
    return rPair;
}
