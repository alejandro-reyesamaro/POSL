#include "golfers_single_swap_packer.h"

int bSize(vector<T_SwapChanges> _changes);

GolfersSingleSwapPacker::GolfersSingleSwapPacker(vector<int> current_config,
                                                 int _neighborhood_size,
                                                 vector<T_SwapChanges> _changes)
    : NeighborhoodPacker(current_config, _neighborhood_size, current_config.size() + 3 + bSize(_changes), bSize(_changes)),
      changes(_changes)
{}

int bSize(vector<T_SwapChanges> _changes)
{
    // Each change (deg, pos and value 2 times)
    return _changes.size() * 5;
}

void GolfersSingleSwapPacker::packBody()
{
    int count = 0;
    for(vector<T_SwapChanges>::iterator it = changes.begin(); it != changes.end(); ++it)
    {
        body[count++] = 2;
        body[count++] = (*it).pos1;
        body[count++] = configuration[(*it).pos2];
        body[count++] = (*it).pos2;
        body[count++] = configuration[(*it).pos1];
    }
}
