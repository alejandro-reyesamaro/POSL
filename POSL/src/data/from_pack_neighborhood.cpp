#include "from_pack_neighborhood.h"

#include <algorithm>

vector<int> InitConfiguration(int * pack);

FromPackNeighborhood::FromPackNeighborhood(int * pack)
    : Neighborhood(InitConfiguration(pack))
{    
    int conf_size = pack[1];
    pack+= conf_size + 2;
    int n_size = *pack;
    pack++;

    for(int i = 0; i < n_size; i++)
    {
        int deg = *pack;
        pack++;
        vector<int> new_indexes;
        vector<int> new_values;
        for (int j = 0; j < deg; j++)
        {
            new_indexes.push_back(*pack);
            pack++;
            new_values.push_back(*pack);
            pack++;
        }
        T_Changes next_changes = {new_indexes, new_values, deg};
        changes.push_back(next_changes);
    }
}

vector<int> InitConfiguration(int * pack)
{
    vector<int> conf(pack[1]);
    copy(&pack[2], &pack[2] + pack[1], conf.begin());
    return conf;
}

FactoryPacker * FromPackNeighborhood::BuildPacker(){ throw "Not implemented yet"; }

vector<int> FromPackNeighborhood::neighborAt(int index){ return applyChangeAt(index); }

vector<int> FromPackNeighborhood::applyChangeAt(int index)
{
    if(index >= size()) return current_configuration;
    copy(current_configuration.begin(), current_configuration.end(), configuration_changed.begin());
    for (unsigned int i = 0;  i < changes[index].positions.size(); i++)
        configuration_changed[changes[index].positions[i]] = changes[index].new_values[i];
    return configuration_changed;
}
