#pragma once

#include "factory_packer.h"
#include "../packers/one_change_neighborhood_packer.h"

class FactoryOneChangeNeighborhoodPacker : public FactoryPacker
{
    public:
        FactoryOneChangeNeighborhoodPacker(vector<int> config,
                                           int neighborhood_size,
                                           vector<T_change> _changes);
};
