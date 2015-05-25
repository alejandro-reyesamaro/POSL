#pragma once

#include "v_search_state.h"

class FirstImprovement_VSearchState : public VSearchState
{
    public:
        FirstImprovement_VSearchState();
        bool keepSearching();
};
