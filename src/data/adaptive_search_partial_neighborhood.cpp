#include "adaptive_search_partial_neighborhood.h"
#include "dStrategy/elements_change_iterator.h"
#include "../tools/tools.h"
#include "dStrategy/single_swap_apply_change_behavior.h"
#include "dStrategy/elements_change_iterator.h"

#include <algorithm>
#include <iostream>

using namespace std;

AdaptiveSearchPartialNeighborhood::AdaptiveSearchPartialNeighborhood(shared_ptr<Benchmark> _benchmark, int _part)
    : Neighborhood(_benchmark->Dimension()),
      benchmark(_benchmark),
      variables_to_analize(_benchmark->Dimension() / _part - 1),
      changeAtBhv(make_shared<SingleSwapApplyChangeBehavior>(_benchmark->Dimension())),
      monotony(Tools::generateMonotony(benchmark->Dimension())),
      bad_variables(_benchmark->Dimension()),
      cost_n_variable(_benchmark->Dimension())
{}

shared_ptr<POSL_Iterator> AdaptiveSearchPartialNeighborhood::getIterator()
{
    return make_shared<ElementsChangeIterator>(shared_from_this());
}

void AdaptiveSearchPartialNeighborhood::Init(shared_ptr<PSP> psp, vector<int> & _configuration)
{
    std::copy(_configuration.begin(), _configuration.end(), current_configuration.begin());
    updateChanges(psp->GetRandomizer());
}

int AdaptiveSearchPartialNeighborhood::sickestVariableOnRange(shared_ptr<Randomizer> rand)
{
    //cout << "IN" << endl;
    bad_variables.clear();
    int cost_on_variable;
    int worst_cost_on_variable = benchmark->costOnVariable(monotony[0]);
    bad_variables.pushBack(monotony[0]);
    for(int i = 1; i <= variables_to_analize; i++)
    {
        cost_on_variable = benchmark->costOnVariable(monotony[i]);
        if (cost_on_variable == worst_cost_on_variable)
            bad_variables.pushBack(monotony[i]);
        else if(cost_on_variable > worst_cost_on_variable)
        {
            worst_cost_on_variable = cost_on_variable;
            bad_variables.clear();
            bad_variables.pushBack(monotony[i]);
        }
    }
    //cout << "OUT" << endl;
    return bad_variables.elementAt(rand->NextInt(0, bad_variables.size()-1));
}

//! Sorts (decreasing) monotony taking into account the cost_on_variable vector
//! so, monotoni[0] is the worst variable
void AdaptiveSearchPartialNeighborhood::sickestVariables()
{
    monotony = Tools::generateMonotony(benchmark->Dimension());
    for(unsigned int i = 0; i < monotony.size(); i++)
        cost_n_variable[i] = benchmark->costOnVariable(i);
    //! cpp.sh/4jo7z
    std::sort(monotony.begin(),
              monotony.end(),
              [&](std::size_t i, std::size_t j){ return cost_n_variable[i] > cost_n_variable[j]; });
}

//! For PARTIAL but random

void AdaptiveSearchPartialNeighborhood::updateChanges(shared_ptr<Randomizer> rand)
{
    changes.clear();
    rand->vector_shuffle(monotony);
    int bad_variable = sickestVariableOnRange(rand);
    for(int i = 0; i <= variables_to_analize; i++)
    {
        if(monotony[i] == bad_variable) continue;
        std::vector<int> new_indexes ({bad_variable, monotony[i]});
        std::vector<int> new_values ({current_configuration[bad_variable], current_configuration[monotony[i]]});

        T_Changes next_changes = {new_indexes, new_values, (int)new_values.size()};
        changes.push_back(next_changes);
    }
}


/*
void AdaptiveSearchPartialNeighborhood::updateChanges(shared_ptr<Randomizer> rand)
{
    changes.clear();
    sickestVariables();
    for(int i = 1; i <= variables_to_analize; i++)
    {
        std::vector<int> new_indexes ({monotony[0], monotony[i]});
        std::vector<int> new_values ({current_configuration[monotony[0]], current_configuration[monotony[i]]});

        T_Changes next_changes = {new_indexes, new_values, (int)new_values.size()};
        changes.push_back(next_changes);
    }
}
*/

std::shared_ptr<FactoryPacker> AdaptiveSearchPartialNeighborhood::BuildPacker(){ throw "Not implemented yet"; }

std::vector<int> AdaptiveSearchPartialNeighborhood::neighborAt(int index)
{
    return changeAtBhv->applyChangeAt(index, current_configuration, changes);
}
