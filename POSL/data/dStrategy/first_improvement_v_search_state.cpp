#include "first_improvement_v_search_state.h"

FirstImprovement_VSearchState::FirstImprovement_VSearchState()
{
}

bool FirstImprovement_VSearchState::keepSearching()
{
    return it->SomeNext() && (best_cost <= found_cost);
}
