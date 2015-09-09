#include "golfers_single_swap_packer.h"

using namespace std;

int GbSize(vector<T_Changes> _changes);

GolfersSingleSwapPacker::GolfersSingleSwapPacker(vector<int> current_config,
                                                 int _neighborhood_size,
                                                 vector<T_Changes> _changes)
    : NeighborhoodPacker(current_config, _neighborhood_size, current_config.size() + 3 + GbSize(_changes), GbSize(_changes)),
      changes(_changes)
{}

int GbSize(vector<T_Changes> _changes)
{
    // Each change (deg, pos and value 2 times)
    return _changes.size() * 5;
}

void GolfersSingleSwapPacker::packBody()
{
    int count = 0;
    for(vector<T_Changes>::iterator it = changes.begin(); it != changes.end(); ++it)
    {
        body[count++] = 2;
        body[count++] = (*it).positions[0];
        body[count++] = configuration[(*it).positions[1]];
        body[count++] = (*it).positions[1];
        body[count++] = configuration[(*it).positions[0]];
    }
}
