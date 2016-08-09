#include "adaptive_search_range_neighborhood.h"
#include "dStrategy/elements_change_iterator.h"
#include "../tools/tools.h"
#include "dStrategy/single_swap_apply_change_behavior.h"
#include "dStrategy/elements_change_iterator.h"

#include <algorithm>
#include <iostream>

using namespace std;

AdaptiveSearchRangeNeighborhood::AdaptiveSearchRangeNeighborhood(shared_ptr<Benchmark> _benchmark, int _a, int _b)
    : Neighborhood(_benchmark->Dimension()),
      benchmark(_benchmark),
      a(min(max(0, _a), _benchmark->Dimension()-1)),
      b(min(_b, _benchmark->Dimension()-1)),
      changeAtBhv(make_shared<SingleSwapApplyChangeBehavior>(_benchmark->Dimension())),
      monotony(Tools::generateMonotony(a, b)),
      bad_variables((b-a) + 1)
{}

shared_ptr<POSL_Iterator> AdaptiveSearchRangeNeighborhood::getIterator()
{
    return make_shared<ElementsChangeIterator>(shared_from_this());
}

void AdaptiveSearchRangeNeighborhood::Init(shared_ptr<PSP> psp, vector<int> & _configuration)
{
    std::copy(_configuration.begin(), _configuration.end(), current_configuration.begin());
    updateChanges(psp->GetRandomizer());
}

int AdaptiveSearchRangeNeighborhood::sickestVariableOnRange()
{
    //cout << "IN" << endl;
    bad_variables.clear();
    int cost_on_variable;
    int worst_cost_on_variable = benchmark->costOnVariable(a);
    bad_variables.pushBack(a);
    for(int i = a+1; i <= b; i++)
    {
        cost_on_variable = benchmark->costOnVariable(i);
        if (cost_on_variable == worst_cost_on_variable)
            bad_variables.pushBack(i);
        else if(cost_on_variable > worst_cost_on_variable)
        {
            worst_cost_on_variable = cost_on_variable;
            bad_variables.clear();
            bad_variables.pushBack(i);
        }
    }
    //cout << "OUT" << endl;
    return bad_variables.elementAt(r_gen.next_int(0, bad_variables.size()-1));
}

void AdaptiveSearchRangeNeighborhood::updateChanges(shared_ptr<Randomizer> rand)
{
    changes.clear();
    rand->vector_shuffle(monotony);
    int bad_variable = sickestVariableOnRange();

    for(unsigned int i = 0; i <= monotony.size(); i++)
    {
        if(monotony[i] == bad_variable) continue;
        std::vector<int> new_indexes ({bad_variable, monotony[i]});
        std::vector<int> new_values ({current_configuration[bad_variable], current_configuration[monotony[i]]});

        T_Changes next_changes = {new_indexes, new_values, (int)new_values.size()};
        changes.push_back(next_changes);
    }
}

std::shared_ptr<FactoryPacker> AdaptiveSearchRangeNeighborhood::BuildPacker(){ throw "Not implemented yet"; }

std::vector<int> AdaptiveSearchRangeNeighborhood::neighborAt(int index)
{
    return changeAtBhv->applyChangeAt(index, current_configuration, changes);
}
