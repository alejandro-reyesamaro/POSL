#include "strategy_search_in_neighborhood.h"

StrategySearchInNeighborhood::StrategySearchInNeighborhood(VSearchState *_search_state)
    : search_state(_search_state)
{}

DecisionPair * StrategySearchInNeighborhood::select(PSP *psp, Neighborhood * V)
{
    Solution * current_solution = psp->GetCurrentSolution();
    Solution * best_solution = psp->GetBestSolutionSoFar();
    int current_cost = psp->CurrentCost();
    int best_cost = psp->BestCostSoFar();

    POSL_Iterator<vector<int>> * it = V->getIterator();
    search_state->updateState(psp->GetBenchmark(), it, current_solution, current_cost, psp->GetBestSolutionSoFar(), psp->BestCostSoFar(), current_solution, current_cost);

    Solution * best_found = best_solution;
    int now_the_cost = current_cost;

    Solution * sol;
    it->Reset();


    while(search_state->keepSearching())
    {
        vector<int> config = it->GetNext();
        sol = new Solution(psp->GetBenchmark()->GetSolution()->domains, config);
        int c = psp->GetBenchmark()->solutionCost(sol);
        if(c < now_the_cost)
        {
            now_the_cost = c;
            best_found = sol;
        }

        search_state->updateState(psp->GetBenchmark(), it, current_solution, current_cost, best_solution, best_cost, best_found, now_the_cost);
    }
    DecisionPair * p = new DecisionPair(search_state->GetCurrentSolution(), search_state->GetFoundSolution());
    return p;
}
