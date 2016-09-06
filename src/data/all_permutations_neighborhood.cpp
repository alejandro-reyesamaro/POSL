#include "all_permutations_neighborhood.h"
#include "dStrategy/elements_change_iterator.h"
#include "../tools/tools.h"
#include "dStrategy/single_swap_apply_change_behavior.h"
#include "dStrategy/elements_change_iterator.h"

#include <algorithm>
#include <iostream>

using namespace std;

AllPermutationsNeighborhood::AllPermutationsNeighborhood(int _config_size, int part)
    : Neighborhood(_config_size),
      changeAtBhv(make_shared<SingleSwapApplyChangeBehavior>(_config_size)),
      monotony(Tools::generateMonotony(_config_size)),
      variables_to_analize(_config_size/part - 1)
{}

shared_ptr<POSL_Iterator> AllPermutationsNeighborhood::getIterator()
{
    return std::make_shared<ElementsChangeIterator>(shared_from_this());
}

void AllPermutationsNeighborhood::Init(shared_ptr<PSP> psp, vector<int> & _configuration)
{
    std::copy(_configuration.begin(), _configuration.end(), current_configuration.begin());
    updateChanges(psp->GetRandomizer());
}

void AllPermutationsNeighborhood::updateChanges(shared_ptr<Randomizer> rand)
{
    changes.clear();
    int n = current_configuration.size();

    rand->vector_shuffle(monotony);
    //int index = rand.next_int(0, n-1)

    for(int i = 0; i < variables_to_analize; i++)
        for(int j = i; j <= variables_to_analize; j++)
        {
            vector<int> new_indexes ({monotony[i], monotony[j]});
            vector<int> new_values ({current_configuration[monotony[j]], current_configuration[monotony[i]]});

            T_Changes next_changes = {new_indexes, new_values, (int)new_values.size()};
            changes.push_back(next_changes);
        }
}

shared_ptr<FactoryPacker> AllPermutationsNeighborhood::BuildPacker(){ throw "Not implemented yet"; }

vector<int> AllPermutationsNeighborhood::neighborAt(int index)
{
    return changeAtBhv->applyChangeAt(index, current_configuration, changes);
}
