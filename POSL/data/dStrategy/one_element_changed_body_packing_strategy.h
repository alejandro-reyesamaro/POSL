#pragma once

#include "neighborhood_body_packing_strategy.h"
#include "../one_element_changed_neighborhood.h"

class OneElementChangedBodyPackingStrategy : public NeighborhoodBodyPackingStrategy
{
    public:
        OneElementChangedBodyPackingStrategy(vector<T_change> _changes);
        int bodySize();
        vector<int> packBody();

    private:
        vector<T_change> changes;
};
