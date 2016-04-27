#include "costas_array_relative_cost_strategy.h"
#include "../../tools/tools.h"
#include "default_sickest_variable_strategy.h"

#include <iostream>
#include <algorithm>

using namespace std;

CostasArrayRelativeCostStrategy::CostasArrayRelativeCostStrategy(int n)
    : //N(n),
      ca_str(make_shared<CostasArrayCostStructure>(n)),
      //bad_variables(n),
      sickest_variable_strategy(make_shared<DefaultSickestVariableStrategy>(n, dynamic_pointer_cast<ProjectableCost>(ca_str)))
{}

void CostasArrayRelativeCostStrategy::initializeCostData(vector<int> & _configuration, int initial_cost)
{
    ca_str->init(_configuration);
    if(initial_cost != ca_str->CurrentCost)
        throw "(POSL Exception) Not matching costs (CostasArrayRelativeCostStrategy::initializeCostData)";
}

void CostasArrayRelativeCostStrategy::updateConfiguration(vector<int> & new_config)
{
    T_Changes changes = Tools::GetChanges(ca_str->Configuration, new_config);
    if(changes.dim > 0)
        relativeSolutionCost(new_config, changes);
}

int CostasArrayRelativeCostStrategy::relativeSolutionCost(vector<int> & _configuration)
{
    T_Changes changes = Tools::GetChanges(ca_str->Configuration, _configuration);
    return relativeSolutionCost(_configuration, changes);
}

int CostasArrayRelativeCostStrategy::relativeSolutionCost(std::vector<int> & new_config, T_Changes)
{
    ca_str ->init(new_config);
    return ca_str->CurrentCost;
}

vector<int> CostasArrayRelativeCostStrategy::Reset()
{
    ca_str->Reset();
    return ca_str->Configuration;
}

int CostasArrayRelativeCostStrategy::costOnVariable(int i)
{
    return ca_str->costOnVariable(i);
}

int CostasArrayRelativeCostStrategy::sickestVariable()
{
    return sickest_variable_strategy->sickestVariable();
}
