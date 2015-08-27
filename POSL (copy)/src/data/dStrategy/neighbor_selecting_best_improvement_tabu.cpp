#include "neighbor_selecting_best_improvement_tabu.h"

#define TABU_SIZE 10

NeighborSelectingBestImprovementTabu::NeighborSelectingBestImprovementTabu()
    : tabu_list(new TabuList(TABU_SIZE))
{}

DecisionPair * NeighborSelectingBestImprovementTabu::select(PSP *psp, Neighborhood * V)
{
    Solution * current_solution = psp->GetCurrentSolution();
    int current_cost = psp->CurrentCost();

    //Solution * best_solution = psp->GetBestSolutionSoFar();
    //int best_cost = psp->BestCostSoFar();

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
        if(c < best_found_cost && !tabu_list->isTabu(sol))
        {
            best_found_cost = c;
            best_found      = sol;
        }
    }
    tabu_list->push(best_found);
    DecisionPair * p = new DecisionPair(current_solution, best_found);
    return p;
}
