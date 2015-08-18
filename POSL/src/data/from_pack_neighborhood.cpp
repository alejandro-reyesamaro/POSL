#include "from_pack_neighborhood.h"
#include "dStrategy/neighborhood_packing_strategy.h"
#include "dStrategy/multi_elements_changed_body_packing_strategy.h"
#include "dStrategy/elements_change_iterator.h"

#include <algorithm>

FromPackNeighborhood::FromPackNeighborhood(int * pack)//(int pack_size, int * pack)
{
    //int count = 0;
    // ID
    //int id = *pack;
    pack ++;
    // CONF_SIZE
    int conf_size = * pack;
    pack++;
    // CONFIGURATION
    for(int i = 0; i < conf_size; i++)
    {
        configuration.push_back(*pack);
        pack++;
    }
    // N_SIZE
    int n_size = *pack;
    pack++;

    //count = conf_size + 3;

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
        T_Nchanges next_changes = {new_indexes, new_values, deg};
        changes.push_back(next_changes);
    }
    packing_strategy = new NeighborhoodPackingStrategy(configuration, size(), new MultiElementsChangedBodyPackingStrategy(changes));
}

POSL_Iterator<vector<int>> * FromPackNeighborhood::getIterator()
{
    POSL_Iterator<vector<int>> * iter = new ElementsChangeIterator(this);
    return iter;
}

int FromPackNeighborhood::size()
{
    return changes.size();
}

vector<int> FromPackNeighborhood::operator[](int index)
{
    return applyChangeAt(index);
}

vector<int> FromPackNeighborhood::applyChangeAt(int index)
{
    if(index >= size()) return configuration;
    vector<int> conf(configuration.size());
    copy(configuration.begin(), configuration.end(), conf.begin());
    for (unsigned int i = 0;  i < changes[index].positions.size(); i++)
        conf[changes[index].positions[i]] = changes[index].new_values[i];
    return conf;
}

vector<int> FromPackNeighborhood::pack()
{
    return packing_strategy->pack();
}

int FromPackNeighborhood::bodySize()
{
    return packing_strategy->BodySize();
}

vector<int> FromPackNeighborhood::body()
{
    return packing_strategy->body();
}
