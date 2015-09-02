#pragma once

#include "neighborhood_packer.h"
#include "../../data/golfers_single_swap_neighborhood.h"

class GolfersSingleSwapPacker : public NeighborhoodPacker
{
    public:
        GolfersSingleSwapPacker(vector<int> current_config,
                                int _neighborhood_size,
                                vector<T_SwapChanges> _changes);

    protected:
        void packBody();

        vector<T_SwapChanges> changes;
};
