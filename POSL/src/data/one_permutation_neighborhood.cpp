#include "one_permutation_neighborhood.h"
#include "dStrategy/elements_change_iterator.h"
#include "../tools/tools.h"
#include "dStrategy/single_swap_apply_change_behavior.h"

#include <algorithm>
#include <iostream>
#include <chrono>

OnePermutationNeighborhood::OnePermutationNeighborhood(Solution * sol)
    : Neighborhood(sol->GetConfiguration()),
      changeAtBhv(new SingleSwapApplyChangeBehavior(sol->GetConfiguration().size())),
      monotony(Tools::generateMonotony(sol->GetConfiguration().size()))
{
    updateChanges();
}

void OnePermutationNeighborhood::update(vector<int> _configuration)
{
    copy(_configuration.begin(), _configuration.end(), current_configuration.begin());
    updateChanges();
}

void OnePermutationNeighborhood::updateChanges()
{
    int n = current_configuration.size();
    int n_changes = n/2;

    Tools::shuffle(monotony);

    for(int i = 0; i < n_changes; i++)
    {
        vector<int> new_indexes ({monotony[2*i], monotony[2*1 + 1]});
        vector<int> new_values ({current_configuration[monotony[2*1 + 1]], current_configuration[monotony[2*i]]});

        T_Changes next_changes = {new_indexes, new_values, new_values.size()};
        changes.push_back(next_changes);
    }
}

FactoryPacker * OnePermutationNeighborhood::BuildPacker(){ throw "Not implemented yet"; }

vector<int> OnePermutationNeighborhood::neighborAt(int index)
{
    return changeAtBhv->applyChangeAt(index, current_configuration, changes);// return applyChangeAt(index);
}
