#pragma once

#include "factory_packer.h"
#include "../packers/golfers_single_swap_packer.h"

class FactoryGolfersSingleSwapNeighborhoodPacker : public FactoryPacker
{
    public:
        FactoryGolfersSingleSwapNeighborhoodPacker(vector<int> config, int neighborhood_size, vector<T_SwapChanges> _changes);
};
