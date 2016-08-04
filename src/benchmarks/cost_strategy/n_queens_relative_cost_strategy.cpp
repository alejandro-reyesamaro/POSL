#include "n_queens_relative_cost_strategy.h"
#include "../../tools/tools.h"
#include "default_sickest_variable_strategy.h"

#include <iostream>
#include <algorithm>

using namespace std;

NQueensRelativeCostStrategy::NQueensRelativeCostStrategy(int n)
    : nq_str(make_shared<NQueensCostStructure>(n)),
      sickest_variable_strategy(make_shared<DefaultSickestVariableStrategy>(n, dynamic_pointer_cast<ProjectableCost>(nq_str)))
{}

void NQueensRelativeCostStrategy::initializeCostData(std::vector<int> &_configuration, int _initial_cost)
{
    nq_str->set(_configuration);
    if(_initial_cost != nq_str->CurrentCost)
        throw "(POSL Exception) Not matching costs (NQueensRelativeCostStrategy::initializeCostData)";
}

void NQueensRelativeCostStrategy::updateConfiguration(std::vector<int> &new_config)
{
    T_Changes changes = Tools::GetChanges(nq_str->Configuration, new_config);
    if(changes.dim > 0)
        relative_cost(new_config, changes, true);
}

int NQueensRelativeCostStrategy::relative_cost(std::vector<int> & new_config, T_Changes change, bool updating)
{
    return nq_str->relative_cost(new_config, change, updating);
    //nq_str->set(new_config);
    //return nq_str->CurrentCost;
}

int NQueensRelativeCostStrategy::relativeSolutionCost(std::vector<int> & _configuration)
{
    T_Changes changes = Tools::GetChanges(nq_str->Configuration, _configuration);
    return relativeSolutionCost(_configuration, changes);
    //nq_str->set(_configuration);
    //return nq_str->CurrentCost;
}

int NQueensRelativeCostStrategy::relativeSolutionCost(std::vector<int> &_configuration, T_Changes change)
{
    return relative_cost(_configuration, change, false);
    //nq_str->set(_configuration);
    //return nq_str->CurrentCost;
}

int NQueensRelativeCostStrategy::costOnVariable(int variable_index)
{
    return nq_str->costOnVariable(variable_index);
}

int NQueensRelativeCostStrategy::sickestVariable()
{
    return sickest_variable_strategy->sickestVariable();
}
