#include "best_improvement_tabu_v_search_state.h"

BestImprovementTabu_VSearchState::BestImprovementTabu_VSearchState(TabuList * _tabu_list) : tabu_list(_tabu_list)
{
}

bool BestImprovementTabu_VSearchState::keepSearching()
{
    return it->SomeNext();
}

void BestImprovementTabu_VSearchState::updateState(Benchmark * _bench,
                               POSL_Iterator<vector<int>> * _it,
                               Solution *current_solution,
                               int _current_cost,
                               Solution *best_solution,
                               int _best_cost,
                               Solution *found_solution,
                               int _found_cost)
{
    bench = _bench;
    it = _it;
    current = current_solution;
    current_cost = _current_cost;
    best = best_solution;
    best_cost = _best_cost;
    if(!tabu_list->isTabu(found_solution))
    {
        found = found_solution;
        found_cost = _found_cost;
    }
}
