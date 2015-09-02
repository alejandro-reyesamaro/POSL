#include "one_change_neighborhood_packer.h"

int bSize(vector<T_change> _changes);

OneChangeNeighborhoodPacker::OneChangeNeighborhoodPacker(vector<int> current_config,
                                                         int _neighborhood_size,
                                                         vector<T_change> _changes)
    : NeighborhoodPacker(current_config, _neighborhood_size, current_config.size() + 3 + bSize(_changes), bSize(_changes)),
      changes(_changes)
{}

int bSize(vector<T_change> _changes)
{
    // Each change * (deg, pos and value)
    return _changes.size() * 3;
}

void OneChangeNeighborhoodPacker::packBody()
{
    int count = 0;
    for(vector<T_change>::iterator it = changes.begin(); it != changes.end(); ++it)
    {
        body[count++] = 1;
        body[count++] = (*it).pos;
        body[count++] = (*it).new_value;
    }
}
