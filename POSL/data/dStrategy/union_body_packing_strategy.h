#pragma once

#include "neighborhood_body_packing_strategy.h"
#include "packable.h"

class UnionBodyPackingStrategy : public NeighborhoodBodyPackingStrategy
{
    public:
        UnionBodyPackingStrategy(Packable * _V1, Packable * _V2);
        int bodySize();
        int * packBody();

    private:
        Packable * V1, * V2;
};
