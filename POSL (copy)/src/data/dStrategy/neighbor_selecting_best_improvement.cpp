#include "neighbor_selecting_best_improvement.h"

NeighborSelectingBestImprovement::NeighborSelectingBestImprovement()
{}

DecisionPair * NeighborSelectingBestImprovement::select(PSP *psp, Neighborhood * V)
{
    Solution * current_solution = psp->GetCurrentSolution();
    int current_cost = psp->CurrentCost();

    POSL_Iterator<vector<int>> * it = V->getIterator();

    Solution * best_found = current_solution;
    int best_found_cost = current_cost;

    Solution * sol;
    it->Reset();


    while(it->SomeNext())
    {
        vector<int> config = it->GetNext();
        sol = new Solution(psp->GetBenchmark()->GetSolution()->domains, config);
        int c = psp->GetBenchmark()->solutionCost(sol);
        if(c < best_found_cost)
        {
            best_found_cost = c;
            best_found      = sol;
        }
    }
    DecisionPair * p = new DecisionPair(current_solution, best_found);
    return p;
}
