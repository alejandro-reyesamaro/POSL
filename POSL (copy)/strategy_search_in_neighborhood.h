#pragma once

#include "neighborhood.h"
#include "decision_pair.h"
#include "benchmark.h"
#include "v_search_state.h"

class StrategySearchInNeighborhood
{
    public:
        StrategySearchInNeighborhood(VSearchState * _search_state);
        DecisionPair * select(Benchmark * bench, Neighborhood * V);
    private:
        VSearchState * search_state;
};

