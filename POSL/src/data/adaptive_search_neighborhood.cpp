#include "adaptive_search_neighborhood.h"
#include "dStrategy/elements_change_iterator.h"
#include "../tools/tools.h"
#include "dStrategy/single_swap_apply_change_behavior.h"
#include "dStrategy/elements_change_iterator.h"

#include <algorithm>
#include <iostream>

using namespace std;

AdaptiveSearchNeighborhood::AdaptiveSearchNeighborhood(shared_ptr<Benchmark> _benchmark)
    : Neighborhood(_benchmark->Dimension()),
      benchmark(_benchmark),
      changeAtBhv(make_shared<SingleSwapApplyChangeBehavior>(_benchmark->Dimension())),
      monotony(Tools::generateMonotony(_benchmark->Dimension()))
{}

shared_ptr<POSL_Iterator> AdaptiveSearchNeighborhood::getIterator()
{
    return make_shared<ElementsChangeIterator>(shared_from_this());
}

void AdaptiveSearchNeighborhood::Init(shared_ptr<PSP> psp, vector<int> & _configuration)
{
    std::copy(_configuration.begin(), _configuration.end(), current_configuration.begin());
    updateChanges(psp->GetRandomizer());
}

void AdaptiveSearchNeighborhood::updateChanges(shared_ptr<Randomizer> rand)
{
    changes.clear();
    rand->vector_shuffle(monotony);
    int bad_variable = benchmark->sickestVariable();

    for(unsigned int i = 0; i < current_configuration.size(); i++)
    {
        if(monotony[i] == bad_variable) continue;
        std::vector<int> new_indexes ({bad_variable, monotony[i]});
        std::vector<int> new_values ({current_configuration[bad_variable], current_configuration[monotony[i]]});

        T_Changes next_changes = {new_indexes, new_values, new_values.size()};
        changes.push_back(next_changes);
    }
}

std::shared_ptr<FactoryPacker> AdaptiveSearchNeighborhood::BuildPacker(){ throw "Not implemented yet"; }

std::vector<int> AdaptiveSearchNeighborhood::neighborAt(int index)
{
    return changeAtBhv->applyChangeAt(index, current_configuration, changes);
}
