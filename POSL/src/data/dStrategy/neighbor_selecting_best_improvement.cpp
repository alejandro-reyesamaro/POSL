#include "neighbor_selecting_best_improvement.h"

#include <algorithm>

NeighborSelectingBestImprovement::NeighborSelectingBestImprovement(vector<Domain> domains)
    : rPair(new DecisionPair(new Solution(domains), new Solution(domains)))
{}

shared_ptr<DecisionPair> NeighborSelectingBestImprovement::select(shared_ptr<PSP> psp, shared_ptr<Neighborhood> V)
{
    current_config = psp->GetCurrentSolution()->GetConfiguration();
    int current_cost = psp->CurrentCost();
    best_found_config = psp->GetCurrentSolution()->GetConfiguration();
    int best_found_cost = current_cost;

    it = V->getIterator();
    it->Reset();

    while(it->SomeNext())
    {
        vector<int> config = it->GetNext();
        //sol_2_return->UpdateConfiguration(it->GetNext());
        int c = psp->GetBenchmark()->solutionCost(config);
        if(c < best_found_cost)
        {
            best_found_cost   = c;
            best_found_config = config;
        }
    }
    rPair->update(current_config, best_found_config);
    //return new DecisionPair(current_solution, new Solution(psp->GetBenchmark()->Domains(), best_found));
    return rPair;
}
