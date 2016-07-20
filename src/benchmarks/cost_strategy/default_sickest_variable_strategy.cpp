#include "default_sickest_variable_strategy.h"

using namespace std;

DefaultSickestVariableStrategy::DefaultSickestVariableStrategy(int _size, shared_ptr<ProjectableCost> iProjectable_cost)
    : Size(_size),
      projectable_cost_component(iProjectable_cost),
      bad_variables(_size)
{}

int DefaultSickestVariableStrategy::sickestVariable()
{
    bad_variables.clear();
    int cost_on_variable;
    int worst_cost_on_variable = projectable_cost_component->costOnVariable(0);
    bad_variables.pushBack(0);
    for(int i = 1; i < Size; i++)
    {
        cost_on_variable = projectable_cost_component->costOnVariable(i);
        if (cost_on_variable == worst_cost_on_variable)
            bad_variables.pushBack(i);
        else if(cost_on_variable > worst_cost_on_variable)
        {
            worst_cost_on_variable = cost_on_variable;
            bad_variables.clear();
            bad_variables.pushBack(i);
        }
    }
    return bad_variables.elementAt(r_gen.next_int(0, bad_variables.size()-1));
}
