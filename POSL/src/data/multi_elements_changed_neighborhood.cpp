#include "multi_elements_changed_neighborhood.h"
#include "../tools/rand_index_generator.h"
#include "../packing/factory/factory_multi_changes_neighborhood_packer.h"
#include "dStrategy/standard_apply_change_behavior.h"
#include "dStrategy/elements_change_iterator.h"

#include <algorithm>
#include <iostream>
#include <chrono>

#define N_NEIGHBORS 10
#define PRC_CHANGES 0.5

MultiElementsChangedNeighborhood::MultiElementsChangedNeighborhood(int _config_size, std::vector<Domain> _domains)
    : Neighborhood(_config_size),
      changeAtBhv(std::make_shared<StandardApplyChangeBehavior>(_config_size)),
      domains(_domains),
      rand()
{
    updateChanges();
}

void MultiElementsChangedNeighborhood::updateChanges()
{
    changes.clear();
    int n = current_configuration.size();
    int ch = N_NEIGHBORS; // to chahge ch elements
    //int N = PRC_CHANGES * n;  // to have N chahges

    RandIndexGenerator rig(n-1);
    std::vector<vector<int>> the_changes = rig.generate();

    int pos_new_value = 0;

    for (std::vector<vector<int>>::iterator it = the_changes.begin(); it != the_changes.end(); ++it)
    {
        std::vector<int> new_indexes = (*it);
        std::vector<int> new_values;

        //cout << "[ ";

        for (std::vector<int>::iterator jt = new_indexes.begin(); jt != new_indexes.end(); ++jt)
        {
            //cout << *jt << " ";

            std::vector<int> posible_values =domains[*jt].GetValues();
            int current_value = current_configuration[*jt];

            std::vector<int>::iterator p = find (posible_values.begin(), posible_values.end(), current_value);
            if(p != posible_values.end())
                posible_values.erase(p); // BEST to do a swap with the first element

            pos_new_value = rand.NextInt(0, posible_values.size()-1);
            new_values.push_back(posible_values[pos_new_value]);
        }

        //cout << "]" << endl;

        T_Changes next_changes = {new_indexes, new_values, new_values.size()};
        changes.push_back(next_changes);
    }
}

std::shared_ptr<POSL_Iterator> MultiElementsChangedNeighborhood::getIterator()
{
    return std::make_shared<ElementsChangeIterator>(shared_from_this());
}

void MultiElementsChangedNeighborhood::Init(std::vector<int> _configuration)
{
    std::copy(_configuration.begin(), _configuration.end(), current_configuration.begin());
    updateChanges();
}

std::shared_ptr<FactoryPacker> MultiElementsChangedNeighborhood::BuildPacker()
{
    return std::make_shared<FactoryMultiChangesNeighborhoodPacker>(current_configuration, size(), changes);
}

std::vector<int> MultiElementsChangedNeighborhood::neighborAt(int index)
{
    return changeAtBhv->applyChangeAt(index, current_configuration, changes);
}
