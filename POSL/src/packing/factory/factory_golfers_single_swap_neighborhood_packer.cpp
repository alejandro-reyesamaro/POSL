#include "factory_golfers_single_swap_neighborhood_packer.h"

using namespace std;

FactoryGolfersSingleSwapNeighborhoodPacker::FactoryGolfersSingleSwapNeighborhoodPacker(vector<int> config,
                                                                                       int neighborhood_size,
                                                                                       vector<T_Changes> _changes)
    : FactoryPacker(make_shared<GolfersSingleSwapPacker>(config, neighborhood_size, _changes))
{}
