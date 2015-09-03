#include "neighbor_selecting_first_improvement.h"

NeighborSelectingFirstImprovement::NeighborSelectingFirstImprovement(vector<Domain> domains)
    : rPair(new DecisionPair(new Solution(domains), new Solution(domains)))
{}

DecisionPair * NeighborSelectingFirstImprovement::select(PSP *psp, Neighborhood * V)
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
        //sol = new Solution(psp->GetBenchmark()->Domains(), config);
        int c = psp->GetBenchmark()->solutionCost(config);
        if(c < best_found_cost)
        {
            best_found_cost   = c;
            best_found_config = config;
            break;
        }
    }
    //DecisionPair * p = new DecisionPair(current_solution, new Solution(psp->GetBenchmark()->Domains(), best_found));
    rPair->update(current_config, best_found_config);
    return rPair;
}
