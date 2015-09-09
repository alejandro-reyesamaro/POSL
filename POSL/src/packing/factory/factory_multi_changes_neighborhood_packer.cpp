#include "factory_multi_changes_neighborhood_packer.h"

using namespace std;

FactoryMultiChangesNeighborhoodPacker::FactoryMultiChangesNeighborhoodPacker(vector<int> config,
                                                                             int neighborhood_size,
                                                                             vector<T_Changes> _changes)
    : FactoryPacker(make_shared<MultiChangesNeighborhoodPacker>(config, neighborhood_size, _changes))
{}
