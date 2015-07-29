#pragma once

#include "neighborhood_body_packing_strategy.h"
#include "../golfers_single_swap_neighborhood.h"

class GolfersSingleSwapBodyPackingStrategy : public NeighborhoodBodyPackingStrategy
{
    public:
        GolfersSingleSwapBodyPackingStrategy(vector<T_SwapChanges> _changes, vector<int> _configuration);
        int bodySize();
        vector<int> packBody();

    private:
        vector<T_SwapChanges> changes;
        vector<int> configuration;
};
