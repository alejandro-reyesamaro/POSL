#pragma once

#include "packing_strategy.h"
#include "../neighborhood.h"
#include "neighborhood_body_packing_strategy.h"

class NeighborhoodPackingStrategy : public PackingStrategy
{
    public:
        NeighborhoodPackingStrategy(vector<int> current_config,
                                    int _neighborhood_size,
                                    NeighborhoodBodyPackingStrategy * _body_packing_strategy);
        int * pack();
        int BodySize();
        int * body();

    private:
        int neighborhood_size;
        vector<int> config;
        NeighborhoodBodyPackingStrategy * body_strategy;
};
