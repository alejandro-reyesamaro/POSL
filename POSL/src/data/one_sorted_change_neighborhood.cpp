#include "one_sorted_change_neighborhood.h"
#include "../tools/tools.h"
#include "dStrategy/sorted_apply_change_behavior.h"
#include "dStrategy/elements_change_iterator.h"

OneSortedChangeNeighborhood::OneSortedChangeNeighborhood(int _config_size)
    : Neighborhood(_config_size),
      changeAtBhv(std::make_shared<SortedApplyChangeBehavior>(_config_size))
{}

std::shared_ptr<POSL_Iterator> OneSortedChangeNeighborhood::getIterator()
{
    return std::make_shared<ElementsChangeIterator>(shared_from_this());
}

void OneSortedChangeNeighborhood::Init(shared_ptr<PSP> psp, std::vector<int> & _configuration)
{
    copy(_configuration.begin(), _configuration.end(), current_configuration.begin());
    updateChanges(psp->GetRandomizer());
}

void OneSortedChangeNeighborhood::updateChanges(shared_ptr<Randomizer> rand)
{
    changes.clear();
    int n = current_configuration.size();

    std::vector<int> indexes = Tools::generateMonotony(1, n-2);
    rand->vector_shuffle(indexes);

    int pos_new_value = 0;

    std::vector<int> posible_values;
    for(int i = 0; i < n-2; ++i)
    {
        int current_value = current_configuration[indexes[i]];
        posible_values = Tools::vector_possible_values_to_hold_sorted(indexes[i], current_configuration);
        rand->vector_shuffle(posible_values);
        int l = posible_values.size();
        for (int j = 0; j <  l ; j++) // or l/2
        {
            pos_new_value = j;
            if(posible_values[pos_new_value] == current_value)
                continue;
            T_Changes next_change = {{indexes[i]}, {posible_values[pos_new_value]}, 1};
            changes.push_back(next_change);
        }
    }
}

std::shared_ptr<FactoryPacker> OneSortedChangeNeighborhood::BuildPacker(){ throw "Not implemented yet"; }

std::vector<int> OneSortedChangeNeighborhood::neighborAt(int index)
{
    return changeAtBhv->applyChangeAt(index, current_configuration, changes);
}
