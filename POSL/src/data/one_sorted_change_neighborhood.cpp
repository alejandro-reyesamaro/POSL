#include "one_sorted_change_neighborhood.h"
#include "../tools/tools.h"
#include "dStrategy/sorted_apply_change_behavior.h"

#include <algorithm>
#include <chrono>

#define N_NEIGHBORS 16

OneSortedChangeNeighborhood::OneSortedChangeNeighborhood(int _config_size)
    : Neighborhood(_config_size),
      changeAtBhv(new SortedApplyChangeBehavior(_config_size))
{
    updateChanges();
}

void OneSortedChangeNeighborhood::Init(vector<int> _configuration)
{
    copy(_configuration.begin(), _configuration.end(), current_configuration.begin());
    updateChanges();
}

void OneSortedChangeNeighborhood::updateChanges()
{
    changes.clear();
    int n = current_configuration.size();

    vector<int> indexes;
    for (int i = 1; i < n-1; i++)
        indexes.push_back(i);
    //n = N_NEIGHBORS;
    Tools::shuffle(indexes);

    int pos_new_value = 0;
    //vector<int> the_configuration = sol->GetConfiguration();

    for(int i = 0; i < n-2; ++i)
    {
        int current_value = current_configuration[indexes[i]];
        vector<int> posible_values = Tools::vector_possible_values_to_hold_sorted(indexes[i],current_configuration);
        Tools::shuffle(posible_values);
        int l = posible_values.size();
        for (int j = 0; j <  l / 2; j++)
        {
            pos_new_value = j;
            if(posible_values[pos_new_value] == current_value)
                continue;
            T_Changes next_change = {{indexes[i]}, {posible_values[pos_new_value]}, 1};
            changes.push_back(next_change);
        }
    }
}

FactoryPacker * OneSortedChangeNeighborhood::BuildPacker(){ throw "Not implemented yet"; }

vector<int> OneSortedChangeNeighborhood::neighborAt(int index)
{
    return changeAtBhv->applyChangeAt(index, current_configuration, changes);
}