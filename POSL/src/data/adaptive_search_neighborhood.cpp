#include "adaptive_search_neighborhood.h"
#include "dStrategy/elements_change_iterator.h"
#include "../tools/tools.h"
#include "dStrategy/single_swap_apply_change_behavior.h"
#include "dStrategy/elements_change_iterator.h"

#include <algorithm>
#include <iostream>

using namespace std;

AdaptiveSearchNeighborhood::AdaptiveSearchNeighborhood(shared_ptr<Benchmark> _benchmark,
                                                       int _config_size)
    : Neighborhood(_config_size),
      benchmark(_benchmark),
      changeAtBhv(make_shared<SingleSwapApplyChangeBehavior>(_config_size)),
      monotony(Tools::generateMonotony(_config_size)),
      bad_variables(_config_size)
{
    updateChanges();
}

shared_ptr<POSL_Iterator> AdaptiveSearchNeighborhood::getIterator()
{
    return make_shared<ElementsChangeIterator>(shared_from_this());
}

void AdaptiveSearchNeighborhood::Init(vector<int> _configuration)
{
    std::copy(_configuration.begin(), _configuration.end(), current_configuration.begin());
    updateChanges();
}

void AdaptiveSearchNeighborhood::updateChanges()
{
    changes.clear();
    bad_variables.clear();

    int n = current_configuration.size();
    Tools::shuffle(monotony);

    int cov;
    int bcov = benchmark->costOnVariable(0);
    bad_variables.pushBack(0);
    for(int i = 1; i < n; i++)
    {
        cov = benchmark->costOnVariable(i);
        if (cov == bcov)
            bad_variables.pushBack(i);
        else if(cov > bcov)
        {
            bcov = cov;
            bad_variables.clear();
            bad_variables.pushBack(i);
        }
    }    

    int bad_variable = bad_variables.elementAt(rand.NextInt(0, bad_variables.size()-1));

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
