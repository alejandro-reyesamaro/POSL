#pragma once

#include "neighborhood_packer.h"

class UnionNeighborhoodPacker : public NeighborhoodPacker
{
    public:
        UnionNeighborhoodPacker(Neighborhood *_V1, Neighborhood *_V2);

    protected:
        void packBody();

        vector<int> configuration;
        int neighborhood_size;
        vector<T_Nchanges> changes;
};
