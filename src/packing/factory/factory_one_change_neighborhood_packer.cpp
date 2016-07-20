#include "factory_one_change_neighborhood_packer.h"

using namespace std;

FactoryOneChangeNeighborhoodPacker::FactoryOneChangeNeighborhoodPacker(vector<int> config,
                                                                       int neighborhood_size,
                                                                       vector<T_Changes> _changes)
    : FactoryPacker(make_shared<OneChangeNeighborhoodPacker>(config, neighborhood_size, _changes))
{}
