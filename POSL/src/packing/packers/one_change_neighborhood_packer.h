#pragma once

#include "neighborhood_packer.h"
#include "../../data/one_element_changed_neighborhood.h"

class OneChangeNeighborhoodPacker : public NeighborhoodPacker
{
    public:
        OneChangeNeighborhoodPacker(std::vector<int> current_config,
                                    int _neighborhood_size,
                                    std::vector<T_Changes> _changes);

    protected:
        void packBody();
        std::vector<T_Changes> changes;
};
