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
        vector<int> pack();
        int BodySize();
        vector<int> body();

        static Neighborhood * unpack(int * pack);

    private:
        void update(vector<int> current_config, int _neighborhood_size);

        int neighborhood_size;
        vector<int> config;
        NeighborhoodBodyPackingStrategy * body_strategy;
        vector<int> package;
};
