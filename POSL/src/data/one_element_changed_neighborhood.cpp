#include "one_element_changed_neighborhood.h"
#include "../packing/factory/factory_one_change_neighborhood_packer.h"
#include "../tools/tools.h"
#include "dStrategy/standard_apply_change_behavior.h"
#include "dStrategy/elements_change_iterator.h"

#include <algorithm>
#include <chrono>

#define N_NEIGHBORS 16

OneElementChangedNeighborhood::OneElementChangedNeighborhood(int _config_size, std::vector<Domain> _domains)
    : Neighborhood(_config_size),
      changeAtBhv(std::make_shared<StandardApplyChangeBehavior>(_config_size)),
      domains(_domains),
      rand(),
      indexes(Tools::generateMonotony(_config_size))
{}

void OneElementChangedNeighborhood::Init(std::vector<int> _configuration)
{
    copy(_configuration.begin(), _configuration.end(), current_configuration.begin());
    updateChanges();
}

std::shared_ptr<POSL_Iterator> OneElementChangedNeighborhood::getIterator()
{
    return std::make_shared<ElementsChangeIterator>(shared_from_this());
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
        std::vector<int> posible_values = domains[indexes[i]].GetValues();
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

std::shared_ptr<FactoryPacker> OneElementChangedNeighborhood::BuildPacker()
{
    return std::make_shared<FactoryOneChangeNeighborhoodPacker>(current_configuration, size(), changes);
}

std::vector<int> OneElementChangedNeighborhood::neighborAt(int index)
{
    return changeAtBhv->applyChangeAt(index, current_configuration, changes);
}
