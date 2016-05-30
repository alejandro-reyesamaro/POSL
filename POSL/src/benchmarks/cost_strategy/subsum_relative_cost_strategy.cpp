#include "subsum_relative_cost_strategy.h"
#include "default_sickest_variable_strategy.h"
#include "../../tools/tools.h"

using namespace std;

SubsumRelativeCostStrategy::SubsumRelativeCostStrategy(vector<int> values, int subsum, int n)
    : cost_structure(make_shared<SubsumCostStructure>(values, subsum, n)),
      sickest_variable_strategy(make_shared<DefaultSickestVariableStrategy>(values.size(),
                                                                            dynamic_pointer_cast<ProjectableCost>(cost_structure)))
{
}

void SubsumRelativeCostStrategy::initializeCostData(std::vector<int> & _configuration, int _initial_cost)
{
    cost_structure->init(_configuration);
    if(_initial_cost != cost_structure->CurrentCost)
        throw "(POSL Exception) Not matching costs (SubsumRelativeCostStrategy::initializeCostData)";
}

void SubsumRelativeCostStrategy::updateConfiguration(std::vector<int> & new_config)
{
    T_Changes changes = Tools::GetChanges(cost_structure->Configuration, new_config);
    if(changes.dim > 0)
        relative_cost(new_config, changes, true);
}

int SubsumRelativeCostStrategy::relativeSolutionCost(std::vector<int> & _configuration)
{
    T_Changes changes = Tools::GetChanges(cost_structure->Configuration, _configuration);
    return relativeSolutionCost(_configuration, changes);
}

int SubsumRelativeCostStrategy::relativeSolutionCost(std::vector<int> & _configuration, T_Changes _change)
{
    return cost_structure->relative_cost(_configuration, _change, false);
}

int SubsumRelativeCostStrategy::currentCost()
{
    return cost_structure->CurrentCost;
}

int SubsumRelativeCostStrategy::sickestVariable()
{
    return sickest_variable_strategy->sickestVariable();
}

int SubsumRelativeCostStrategy::costOnVariable(int variable_index)
{
    return cost_structure->costOnVariable(variable_index);
}

int SubsumRelativeCostStrategy::relative_cost(std::vector<int> & new_config, T_Changes change, bool updating)
{
    return cost_structure->relative_cost(new_config, change, updating);
}
