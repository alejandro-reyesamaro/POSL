#include "multi_changes_neighborhood_packer.h"

int bSize(vector<T_Nchanges> _changes);

MultiChangesNeighborhoodPacker::MultiChangesNeighborhoodPacker(vector<int> current_config,
                                                               int _neighborhood_size,
                                                               vector<T_Nchanges> _changes)
    : NeighborhoodPacker(current_config, _neighborhood_size, current_config.size() + 3 + bSize(_changes), bSize(_changes)),
      changes(_changes)
{}

int bSize(vector<T_Nchanges> _changes)
{
    // Each change * (deg, pos and value)
    int degs = 0;
    for(vector<T_Nchanges>::iterator it = _changes.begin(); it != _changes.end(); ++it)
        degs = degs + (*it).dim * 2;
    return degs + _changes.size();
}

void MultiChangesNeighborhoodPacker::packBody()
{
    int count = 0;
    int k = 0;
    for(vector<T_Nchanges>::iterator it = changes.begin(); it != changes.end(); ++it)
    {
        int deg = changes[k].dim;
        body[count++] = deg;
        for(int i = 0; i < deg; i++)
        {
            int pos = (*it).positions[i];
            int value = (*it).new_values[i];
            body[count++] = pos;
            body[count++] = value;
        }
    }
}
