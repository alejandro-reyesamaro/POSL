#pragma once

#include "packing_strategy.h"
#include "../neighborhood.h"
#include "neighborhood_body_packing_strategy.h"

class NeighborhoodPackingStrategy : public PackingStrategy
{
    public:
        NeighborhoodPackingStrategy(vector<int> current_config,
                                    Neighborhood * _neighborhood,
                                    NeighborhoodBodyPackingStrategy * _body_packing_strategy);
        int * pack();

    private:
        Neighborhood * neighborhood;
        vector<int> config;
        NeighborhoodBodyPackingStrategy * body;
};
