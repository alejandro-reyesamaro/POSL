#pragma once

#include "factory_packer.h"
#include "../packers/one_change_neighborhood_packer.h"

class FactoryOneChangeNeighborhoodPacker : public FactoryPacker
{
    public:
        FactoryOneChangeNeighborhoodPacker(std::vector<int> config,
                                           int neighborhood_size,
                                           std::vector<T_Changes> _changes);
};
