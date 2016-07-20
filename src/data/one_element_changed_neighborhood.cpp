#include "one_element_changed_neighborhood.h"
#include "../packing/factory/factory_one_change_neighborhood_packer.h"
#include "../tools/tools.h"
#include "dStrategy/standard_apply_change_behavior.h"
#include "dStrategy/elements_change_iterator.h"

#include <algorithm>

OneElementChangedNeighborhood::OneElementChangedNeighborhood(int _config_size, std::shared_ptr<Domain> _domain)
    : Neighborhood(_config_size),
      changeAtBhv(std::make_shared<StandardApplyChangeBehavior>(_config_size)),
      domain(_domain),
      indexes(Tools::generateMonotony(_config_size))
{}

void OneElementChangedNeighborhood::Init(shared_ptr<PSP> psp, std::vector<int> & _configuration)
{
    copy(_configuration.begin(), _configuration.end(), current_configuration.begin());
    updateChanges(psp->GetRandomizer());
}

std::shared_ptr<POSL_Iterator> OneElementChangedNeighborhood::getIterator()
{
    return std::make_shared<ElementsChangeIterator>(shared_from_this());
}

void OneElementChangedNeighborhood::updateChanges(shared_ptr<Randomizer> rand)
{
    changes.clear();
    int n = current_configuration.size()/2;

    //n = N_NEIGHBORS;
    rand->vector_shuffle(indexes);
    //int pos_new_value = 0;
    int new_value = 0;

    for(int i = 0; i < n; ++i)
    {
        std::vector<int> posible_values = domain->GetValues(indexes[i]);
        int current_value = current_configuration[indexes[i]];
        //pos_new_value = indexes[i];
        rand->vector_shuffle(posible_values);
        for (unsigned int j = 0; j < posible_values.size(); j++)// / 2 + 1; j++)
        {            
            new_value = posible_values[j];
            if(new_value != current_value)
            {
                T_Changes next_change = {{indexes[i]}, {new_value}, 1};
                changes.push_back(next_change);
            }
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
