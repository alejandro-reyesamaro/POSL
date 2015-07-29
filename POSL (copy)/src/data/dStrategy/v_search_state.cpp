#include "v_search_state.h"

VSearchState::VSearchState()
{
}

void VSearchState::updateState(Benchmark * _bench,
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
    found = found_solution;
    found_cost = _found_cost;
}

Solution * VSearchState::GetCurrentSolution()
{
    return current;
}

Solution * VSearchState::GetFoundSolution()
{
    return found;
}

