#pragma once

#include "neighborhood_packer.h"
#include "../../data/multi_elements_changed_neighborhood.h"

class MultiChangesNeighborhoodPacker : public NeighborhoodPacker
{
    public:
        MultiChangesNeighborhoodPacker(vector<int> current_config,
                                       int _neighborhood_size,
                                       vector<T_Changes> _changes);

    protected:
        void packBody();

        vector<T_Changes> changes;
};
