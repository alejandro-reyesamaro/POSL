#pragma once

#include "neighborhood_body_packing_strategy.h"
#include "packable.h"
#include "../neighborhood.h"

class UnionBodyPackingStrategy : public NeighborhoodBodyPackingStrategy
{
    public:
        UnionBodyPackingStrategy(Neighborhood *_V1, Neighborhood *_V2);
        int bodySize();
        vector<int> packBody();

    private:
        Neighborhood * V1, * V2;
};
