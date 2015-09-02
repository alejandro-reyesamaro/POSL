#pragma once

#include "packing_strategy.h"

class NeighborhoodPackingFromPackStrategy : public PackingStrategy
{
    public:
        NeighborhoodPackingFromPackStrategy(int pack_size, int *_pack);
        vector<int> pack();
        int BodySize();
        vector<int> body();

    private:
        void update(int pack_size, int * _pack);

        vector<int> package;
        vector<int> body_package;
};
