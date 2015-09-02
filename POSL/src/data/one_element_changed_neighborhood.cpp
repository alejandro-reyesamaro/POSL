#include "one_element_changed_neighborhood.h"
#include "../packing/factory/factory_one_change_neighborhood_packer.h"
#include "../tools/tools.h"

#include <algorithm>
#include <chrono>

#define N_NEIGHBORS 16

OneElementChangedNeighborhood::OneElementChangedNeighborhood(Solution * sol)
    : Neighborhood(sol->GetConfiguration()),
      rand(),
      indexes(Tools::generateMonotony(sol->GetConfiguration().size()))
{
    int n = sol->GetConfiguration().size();

    //n = N_NEIGHBORS;
    Tools::shuffle(indexes);
    int pos_new_value = 0;

    for(int i = 0; i < n; ++i)
    {
        vector<int> posible_values = sol->GetDomains()[indexes[i]].GetValues();
        int current_value = sol->GetConfiguration()[indexes[i]];
        Tools::shuffle(posible_values);
        //vector<int>::iterator p = find (posible_values.begin(), posible_values.end(), current_value);
        //if(p != posible_values.end())
        //    posible_values.erase(p); // BEST to do a swap with the first element
        for (int j = 0; j < posible_values.size() / 2 + 1; j++)
        {
            pos_new_value = rand.NextInt(0, posible_values.size()/2);
            if(posible_values[pos_new_value] == current_value)
                continue;
            T_change next_change = {indexes[i], posible_values[pos_new_value]};
            changes.push_back(next_change);
        }
    }
}

FactoryPacker * OneElementChangedNeighborhood::BuildPacker()
{
    return new FactoryOneChangeNeighborhoodPacker(current_configuration, size(), changes);
}

vector<int> OneElementChangedNeighborhood::neighborAt(int index){ return applyChangeAt(index); }

vector<int> OneElementChangedNeighborhood::applyChangeAt(int index)
{
    if(index >= size()) return current_configuration;
    copy(current_configuration.begin(), current_configuration.end(), configuration_changed.begin());
    configuration_changed[changes[index].pos] = changes[index].new_value;
    return configuration_changed;
}
