#include "one_element_changed_neighborhood.h"
#include "../packing/factory/factory_one_change_neighborhood_packer.h"
#include "../tools/tools.h"
#include "dStrategy/standard_apply_change_behavior.h"

#include <algorithm>
#include <chrono>

#define N_NEIGHBORS 16

OneElementChangedNeighborhood::OneElementChangedNeighborhood(Solution * sol)
    : Neighborhood(sol->GetConfiguration()),
      changeAtBhv(new StandardApplyChangeBehavior(sol->GetConfiguration().size())),
      domains(sol->GetDomains()),
      rand(),
      indexes(Tools::generateMonotony(sol->GetConfiguration().size()))
{
    updateChanges();
}

void OneElementChangedNeighborhood::update(vector<int> _configuration)
{
    copy(_configuration.begin(), _configuration.end(), current_configuration.begin());
    updateChanges();
}

void OneElementChangedNeighborhood::updateChanges()
{
    int n = current_configuration.size();

    //n = N_NEIGHBORS;
    Tools::shuffle(indexes);
    int pos_new_value = 0;

    for(int i = 0; i < n; ++i)
    {
        vector<int> posible_values = domains[indexes[i]].GetValues();
        int current_value = current_configuration[indexes[i]];
        Tools::shuffle(posible_values);
        for (int j = 0; j < posible_values.size() / 2 + 1; j++)
        {
            pos_new_value = rand.NextInt(0, posible_values.size()/2);
            if(posible_values[pos_new_value] == current_value)
                continue;
            T_Changes next_change = {{indexes[i]}, {posible_values[pos_new_value]}, 1};
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
    return changeAtBhv->applyChangeAt(index, current_configuration, changes);// return applyChangeAt(index);
}
