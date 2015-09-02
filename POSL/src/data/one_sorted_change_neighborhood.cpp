#include "one_sorted_change_neighborhood.h"
#include "../tools/tools.h"

#include <algorithm>
#include <chrono>

#define N_NEIGHBORS 16

OneSortedChangeNeighborhood::OneSortedChangeNeighborhood(Solution * sol)
    : Neighborhood(sol->GetConfiguration())
{
    int n = current_configuration.size();

    vector<int> indexes;
    for (int i = 1; i < n-1; i++)
        indexes.push_back(i);
    //n = N_NEIGHBORS;
    Tools::shuffle(indexes);

    int pos_new_value = 0;
    vector<int> the_configuration = sol->GetConfiguration();

    for(int i = 0; i < n-2; ++i)
    {
        int current_value = the_configuration[indexes[i]];
        vector<int> posible_values = Tools::vector_possible_values_to_hold_sorted(indexes[i],the_configuration);
        Tools::shuffle(posible_values);
        //vector<int>::iterator p = find (posible_values.begin(), posible_values.end(), current_value);
        //if(p != posible_values.end())
        //    posible_values.erase(p); // BEST to do a swap with the first element
        int l = posible_values.size();
        for (int j = 0; j <  l / 2; j++)
        {
            pos_new_value = j;
            if(posible_values[pos_new_value] == current_value)
                continue;
            T_change next_change = {indexes[i], posible_values[pos_new_value]};
            changes.push_back(next_change);
        }
    }
}

FactoryPacker * OneSortedChangeNeighborhood::BuildPacker(){ throw "Not implemented yet"; }

vector<int> OneSortedChangeNeighborhood::neighborAt(int index){ return applyChangeAt(index); }

vector<int> OneSortedChangeNeighborhood::applyChangeAt(int index)
{
    if(index >= size()) return current_configuration;
    copy(current_configuration.begin(), current_configuration.end(), configuration_changed.begin());
    configuration_changed[changes[index].pos] = changes[index].new_value;
    return configuration_changed;
}
