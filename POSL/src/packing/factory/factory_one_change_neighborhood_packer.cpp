#include "factory_one_change_neighborhood_packer.h"

FactoryOneChangeNeighborhoodPacker::FactoryOneChangeNeighborhoodPacker(vector<int> config,
                                                                       int neighborhood_size,
                                                                       vector<T_Changes> _changes)
    : FactoryPacker(new OneChangeNeighborhoodPacker(config, neighborhood_size, _changes))
{}