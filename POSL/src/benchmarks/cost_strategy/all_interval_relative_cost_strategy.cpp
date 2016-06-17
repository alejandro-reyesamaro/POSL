#include "all_interval_relative_cost_strategy.h"
#include "../../tools/tools.h"
#include "default_sickest_variable_strategy.h"

#include <iostream>
#include <algorithm>

using namespace std;

AllIntervalRelativeCostStrategy::AllIntervalRelativeCostStrategy(int n)
    : cost_str(make_shared<AllIntervalsCostStructure>(n)),
      sickest_variable_strategy(make_shared<DefaultSickestVariableStrategy>(n, dynamic_pointer_cast<ProjectableCost>(cost_str)))
{}

void AllIntervalRelativeCostStrategy::initializeCostData(vector<int> & _configuration, int _initial_cost)
{
    cost_str->init(_configuration);
    if(_initial_cost != cost_str->CurrentCost)
        throw "(POSL Exception) Not matching costs (AllIntervalRelativeCostStrategy::initializeCostData)";
}

void AllIntervalRelativeCostStrategy::updateConfiguration(vector<int> & new_config)
{
    T_Changes changes = Tools::GetChanges(cost_str->Configuration, new_config);
    if(changes.dim > 0)
        relativeSolutionCost(new_config, changes);
}

int AllIntervalRelativeCostStrategy::relativeSolutionCost(vector<int> & _configuration)
{
    T_Changes changes = Tools::GetChanges(cost_str->Configuration, _configuration);
    return relativeSolutionCost(_configuration, changes);
}

int AllIntervalRelativeCostStrategy::relativeSolutionCost(std::vector<int> & new_config, T_Changes)
{
    cost_str ->init(new_config);
    return cost_str->CurrentCost;
}

vector<int> AllIntervalRelativeCostStrategy::Reset()
{
    cost_str->reset();
    return cost_str->Configuration;
}

int AllIntervalRelativeCostStrategy::costOnVariable(int variable_index)
{
    return cost_str->costOnVariable(variable_index);
}

int AllIntervalRelativeCostStrategy::sickestVariable()
{
    //return sickest_variable_strategy->sickestVariable();
    return cost_str->worst_variable();
}
