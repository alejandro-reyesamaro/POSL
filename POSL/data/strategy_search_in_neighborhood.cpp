#include "strategy_search_in_neighborhood.h"

StrategySearchInNeighborhood::StrategySearchInNeighborhood(VSearchState *_search_state)
    : search_state(_search_state)
{}

DecisionPair * StrategySearchInNeighborhood::select(Benchmark * bench, Neighborhood * V)
{
    Solution * current_solution = bench->GetSolution();
    Solution * best_solution = bench->GetSolution();
    int current_cost = bench->solutionCost(current_solution);

    POSL_Iterator<vector<int>> * it = V->getIterator();

    Solution * sol;
    it->Reset();

    search_state->updateState(bench, it, current_cost, current_cost, current_cost);

    while(search_state->keepSearching())
    {
        vector<int> config = it->GetNext();
        sol = new Solution(bench->GetSolution()->domains, config);
        int c = bench->solutionCost(sol);
        if(c < current_cost)
        {
            current_cost = c;
            best_solution = sol;
        }

        search_state->updateState(bench, it, current_cost, current_cost, current_cost);
    }
    DecisionPair * p = new DecisionPair(current_solution, best_solution);
    return p;
}
