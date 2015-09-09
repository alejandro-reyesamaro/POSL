#pragma once

#include "factory_packer.h"
#include "../packers/multi_changes_neighborhood_packer.h"

class FactoryMultiChangesNeighborhoodPacker : public FactoryPacker
{
    public:
        FactoryMultiChangesNeighborhoodPacker(std::vector<int> config, int neighborhood_size, std::vector<T_Changes> _changes);
};
