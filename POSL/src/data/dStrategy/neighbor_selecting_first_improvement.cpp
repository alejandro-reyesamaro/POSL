#include "neighbor_selecting_first_improvement.h"

NeighborSelectingFirstImprovement::NeighborSelectingFirstImprovement()
{}

DecisionPair * NeighborSelectingFirstImprovement::select(PSP *psp, Neighborhood * V)
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
        sol = new Solution(psp->GetBenchmark()->Domains(), config);
        int c = psp->GetBenchmark()->solutionCost(sol);
        if(c < best_found_cost)
        {
            best_found_cost = c;
            best_found      = sol;
            break;
        }
    }
    DecisionPair * p = new DecisionPair(current_solution, best_found);
    return p;
}
