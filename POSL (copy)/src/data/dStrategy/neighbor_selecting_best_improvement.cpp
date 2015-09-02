#include "neighbor_selecting_best_improvement.h"

NeighborSelectingBestImprovement::NeighborSelectingBestImprovement()
{}

DecisionPair * NeighborSelectingBestImprovement::select(PSP *psp, Neighborhood * V)
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
        //sol_2_return->UpdateConfiguration(it->GetNext());
        int c = psp->GetBenchmark()->solutionCost(config);
        if(c < best_found_cost)
        {
            best_found_cost = c;
            best_found      = config;
        }
    }
    //DecisionPair * p = new DecisionPair(current_solution, best_found);
    return new DecisionPair(current_solution, new Solution(psp->GetBenchmark()->Domains(), best_found));
}
