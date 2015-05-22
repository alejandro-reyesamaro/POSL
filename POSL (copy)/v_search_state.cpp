#include "v_search_state.h"

VSearchState::VSearchState()
{
}

void VSearchState::updateState(Benchmark * _bench, POSL_Iterator<vector<int>> * _it, int _current_cost, int _best_cost, int _found_cost)
{
    bench = _bench;
    it = _it;
    current_cost = _current_cost;
    best_cost = _best_cost;
    found_cost = _found_cost;
}
