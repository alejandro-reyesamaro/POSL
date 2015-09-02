#include "factory_golfers_single_swap_neighborhood_packer.h"

FactoryGolfersSingleSwapNeighborhoodPacker::FactoryGolfersSingleSwapNeighborhoodPacker(vector<int> config,
                                                                                       int neighborhood_size,
                                                                                       vector<T_SwapChanges> _changes)
    : FactoryPacker(new GolfersSingleSwapPacker(config, neighborhood_size, _changes))
{}
