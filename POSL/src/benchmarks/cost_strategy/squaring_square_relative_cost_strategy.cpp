#include "squaring_square_relative_cost_strategy.h"
#include "../../tools/tools.h"
#include "default_sickest_variable_strategy.h"

#include <iostream>
#include <algorithm>

using namespace std;

SquaringSquareRelativeCostStrategy::SquaringSquareRelativeCostStrategy(int _size, vector<int> _squares)
    : cost_str(make_shared<SquaringSquareCostStructure>(_size, _squares)),
      sickest_variable_strategy(make_shared<DefaultSickestVariableStrategy>(_squares.size() * 2,
                                                                            dynamic_pointer_cast<ProjectableCost>(cost_str))),
      bad_variables(_squares.size())
{
}

void SquaringSquareRelativeCostStrategy::initializeCostData(std::vector<int> & _configuration, int initial_cost)
{
    cost_str->set(_configuration);
    if(initial_cost != cost_str->CurrentCost)
        throw "(POSL Exception) Not matching costs (SquaringSquareRelativeCostStrategy::initializeCostData)";
}

void SquaringSquareRelativeCostStrategy::updateConfiguration(std::vector<int> & new_config)
{
    T_Changes changes = Tools::GetChanges(cost_str->Configuration, new_config);
    if(changes.dim > 0)
        relativeSolutionCost(new_config, changes);
}

int SquaringSquareRelativeCostStrategy::relativeSolutionCost(std::vector<int> &_configuration)
{
    T_Changes changes = Tools::GetChanges(cost_str->Configuration, _configuration);
    return relativeSolutionCost(_configuration, changes);
}

int SquaringSquareRelativeCostStrategy::relativeSolutionCost(std::vector<int> & new_config, T_Changes change)
{
    return cost_str->relative_cost(new_config, change, false);
}

int SquaringSquareRelativeCostStrategy::costOnVariable(int index)
{
    return cost_str->costOnVariable(index);
}

int SquaringSquareRelativeCostStrategy::sickestVariable()
{
    bad_variables.clear();
    int cov;
    int bcov = costOnVariable(0);
    bad_variables.pushBack(0);
    for(int i = 1; i < bad_variables.capacity(); i++)
    {
        cov = costOnVariable(i);
        if (cov == bcov)
            bad_variables.pushBack(i);
        else if(cov > bcov)
        {
            bcov = cov;
            bad_variables.clear();
            bad_variables.pushBack(i);
        }
    }
    return bad_variables.elementAt(r_gen.next_int(0, bad_variables.size()-1));
}
