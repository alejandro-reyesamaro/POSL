#include "best_improvement_v_search_state.h"

BestImprovement_VSearchState::BestImprovement_VSearchState()
{
}

bool BestImprovement_VSearchState::keepSearching()
{
    return it->SomeNext();
}
