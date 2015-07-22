#pragma once

#include "neighborhood_body_packing_strategy.h"
#include "../multi_elements_changed_neighborhood.h"

class MultiElementsChangedBodyPackingStrategy : public NeighborhoodBodyPackingStrategy
{
    public:
        MultiElementsChangedBodyPackingStrategy(vector<T_Nchanges> _changes);
        int bodySize();
        vector<int> packBody();

    private:
        vector<T_Nchanges> changes;
};
