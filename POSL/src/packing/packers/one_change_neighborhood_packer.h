#pragma once

#include "neighborhood_packer.h"
#include "../../data/one_element_changed_neighborhood.h"

class OneChangeNeighborhoodPacker : public NeighborhoodPacker
{
    public:
        OneChangeNeighborhoodPacker(vector<int> current_config,
                                    int _neighborhood_size,
                                    vector<T_Changes> _changes);

    protected:
        void packBody();
        vector<T_Changes> changes;
};
