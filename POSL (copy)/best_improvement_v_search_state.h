#pragma once

#include "v_search_state.h"

class BestImprovement_VSearchState : public VSearchState
{
    public:
        BestImprovement_VSearchState();
        bool keepSearching();
};
