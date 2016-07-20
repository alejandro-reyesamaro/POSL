#pragma once

#include "factory_packer.h"
#include "../packers/golfers_single_swap_packer.h"

class FactoryGolfersSingleSwapNeighborhoodPacker : public FactoryPacker
{
    public:
        FactoryGolfersSingleSwapNeighborhoodPacker(std::vector<int> config, int neighborhood_size, std::vector<T_Changes> _changes);
};
