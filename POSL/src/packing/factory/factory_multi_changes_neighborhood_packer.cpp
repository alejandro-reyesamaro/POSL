#include "factory_multi_changes_neighborhood_packer.h"

FactoryMultiChangesNeighborhoodPacker::FactoryMultiChangesNeighborhoodPacker(vector<int> config,
                                                                             int neighborhood_size,
                                                                             vector<T_Changes> _changes)
    : FactoryPacker(new MultiChangesNeighborhoodPacker(config, neighborhood_size, _changes))
{}
