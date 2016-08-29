#include "one_permutation_neighborhood.h"
#include "dStrategy/elements_change_iterator.h"
#include "../tools/tools.h"
#include "dStrategy/single_swap_apply_change_behavior.h"
#include "dStrategy/elements_change_iterator.h"

#include <algorithm>
#include <iostream>

using namespace std;

OnePermutationNeighborhood::OnePermutationNeighborhood(int _config_size)
    : Neighborhood(_config_size),
      changeAtBhv(make_shared<SingleSwapApplyChangeBehavior>(_config_size)),
      monotony(Tools::generateMonotony(_config_size))
{}

shared_ptr<POSL_Iterator> OnePermutationNeighborhood::getIterator()
{
    return std::make_shared<ElementsChangeIterator>(shared_from_this());
}

void OnePermutationNeighborhood::Init(shared_ptr<PSP> psp, vector<int> & _configuration)
{
    std::copy(_configuration.begin(), _configuration.end(), current_configuration.begin());
    updateChanges(psp->GetRandomizer());
}

void OnePermutationNeighborhood::updateChanges(shared_ptr<Randomizer> rand)
{
    changes.clear();
    int n = current_configuration.size();
    int n_changes = n/2;

    rand->vector_shuffle(monotony);

    for(int i = 0; i < n_changes; i++)
    {
        vector<int> new_indexes ({monotony[2*i], monotony[2*i + 1]});
        vector<int> new_values ({current_configuration[monotony[2*i + 1]], current_configuration[monotony[2*i]]});

        T_Changes next_changes = {new_indexes, new_values, (int)new_values.size()};
        changes.push_back(next_changes);
    }
}

shared_ptr<FactoryPacker> OnePermutationNeighborhood::BuildPacker(){ throw "Not implemented yet"; }

vector<int> OnePermutationNeighborhood::neighborAt(int index)
{
    return changeAtBhv->applyChangeAt(index, current_configuration, changes);
}
