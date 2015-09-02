#include "neighbor_selecting_first_improvement.h"

NeighborSelectingFirstImprovement::NeighborSelectingFirstImprovement()
{}

DecisionPair * NeighborSelectingFirstImprovement::select(PSP *psp, Neighborhood * V)
{
    current_solution = psp->GetCurrentSolution();
    int current_cost = psp->CurrentCost();

    it = V->getIterator();

    best_found = current_solution->GetConfiguration();
    int best_found_cost = current_cost;

    it->Reset();

    while(it->SomeNext())
    {
        vector<int> config = it->GetNext();
        //sol = new Solution(psp->GetBenchmark()->Domains(), config);
        int c = psp->GetBenchmark()->solutionCost(config);
        if(c < best_found_cost)
        {
            best_found_cost = c;
            best_found      = config;
            break;
        }
    }
    DecisionPair * p = new DecisionPair(current_solution, new Solution(psp->GetBenchmark()->Domains(), best_found));
    return p;
}
