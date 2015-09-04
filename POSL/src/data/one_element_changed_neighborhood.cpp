#include "one_element_changed_neighborhood.h"
#include "../packing/factory/factory_one_change_neighborhood_packer.h"
#include "../tools/tools.h"
#include "dStrategy/standard_apply_change_behavior.h"

#include <algorithm>
#include <chrono>

#define N_NEIGHBORS 16

OneElementChangedNeighborhood::OneElementChangedNeighborhood(int _config_size, vector<Domain> _domains)
    : Neighborhood(_config_size),
      changeAtBhv(new StandardApplyChangeBehavior(_config_size)),
      domains(_domains),
      rand(),
      indexes(Tools::generateMonotony(_config_size))
{}

void OneElementChangedNeighborhood::Init(vector<int> _configuration)
{
    copy(_configuration.begin(), _configuration.end(), current_configuration.begin());
    updateChanges();
}

void OneElementChangedNeighborhood::updateChanges()
{
    changes.clear();
    int n = current_configuration.size()/2;

    //n = N_NEIGHBORS;
    Tools::shuffle(indexes);
    int pos_new_value = 0;
    int new_value = 0;

    for(int i = 0; i < n; ++i)
    {
        vector<int> posible_values = domains[indexes[i]].GetValues();
        int current_value = current_configuration[indexes[i]];
        pos_new_value = indexes[i];
        Tools::shuffle(posible_values);        
        for (int j = 0; j < posible_values.size() / 2 + 1; j++)
        {            
            new_value = posible_values[j];
            if(new_value == current_value)
                continue;
            T_Changes next_change = {{indexes[i]}, {new_value}, 1};
            changes.push_back(next_change);
        }
    }
}

FactoryPacker * OneElementChangedNeighborhood::BuildPacker()
{
    return new FactoryOneChangeNeighborhoodPacker(current_configuration, size(), changes);
}

vector<int> OneElementChangedNeighborhood::neighborAt(int index)
{
    return changeAtBhv->applyChangeAt(index, current_configuration, changes);
}
