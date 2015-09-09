#include "one_change_neighborhood_packer.h"

using namespace std;

int ObSize(vector<T_Changes> _changes);

OneChangeNeighborhoodPacker::OneChangeNeighborhoodPacker(vector<int> current_config,
                                                         int _neighborhood_size,
                                                         vector<T_Changes> _changes)
    : NeighborhoodPacker(current_config, _neighborhood_size, current_config.size() + 3 + ObSize(_changes), ObSize(_changes)),
      changes(_changes)
{}

int ObSize(vector<T_Changes> _changes)
{
    // Each change * (deg, pos and value)
    return _changes.size() * 3;
}

void OneChangeNeighborhoodPacker::packBody()
{
    int count = 0;
    for(vector<T_Changes>::iterator it = changes.begin(); it != changes.end(); ++it)
    {
        body[count++] = 1;
        body[count++] = (*it).positions[0];
        body[count++] = (*it).new_values[0];
    }
}
