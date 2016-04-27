#include "golomb_ruler_relative_cost_strategy.h"
#include "default_sickest_variable_strategy.h"
#include "../../tools/tools.h"

#include <iostream>
#include <algorithm>

using namespace std;

GolombRulerRelativeCostStrategy::GolombRulerRelativeCostStrategy(int _order, int _length)
    : cost_structure(make_shared<GolombRulerCostStructure>(_order,_length)),
      sickest_variable_strategy(make_shared<DefaultSickestVariableStrategy>(_order,
                                                                            dynamic_pointer_cast<ProjectableCost>(cost_structure)))
{
}

void GolombRulerRelativeCostStrategy::initializeCostData(std::vector<int> & _configuration, int initial_cost)
{
    cost_structure->init(_configuration);
    if(initial_cost != cost_structure->CurrentCost)
        throw "(POSL Exception) Not matching costs (GolombRulerRelativeCostStrategy::initializeCostData)";
}

void GolombRulerRelativeCostStrategy::updateConfiguration(std::vector<int> & new_config)
{
    T_Changes changes = Tools::GetChanges(cost_structure->Configuration, new_config);
    if(changes.dim > 0)
        relative_cost(new_config, changes, true);
}

int GolombRulerRelativeCostStrategy::relativeSolutionCost(std::vector<int> & _configuration)
{
    T_Changes changes = Tools::GetChanges(cost_structure->Configuration, _configuration);
    return relativeSolutionCost(_configuration, changes);
}

int GolombRulerRelativeCostStrategy::relativeSolutionCost(std::vector<int> & new_config, T_Changes change)
{
    return cost_structure->relative_cost(new_config, change, false);
}

int GolombRulerRelativeCostStrategy::currentCost()
{
    return cost_structure->CurrentCost;
}

int GolombRulerRelativeCostStrategy::sickestVariable()
{
    return sickest_variable_strategy->sickestVariable();
}

int GolombRulerRelativeCostStrategy::relative_cost(std::vector<int> & new_config, T_Changes change, bool updating)
{
    return cost_structure->relative_cost(new_config, change, updating);
}
