#include "n_queens_relative_cost_strategy.h"
#include "../../tools/tools.h"

#include <iostream>
#include <algorithm>

using namespace std;

NQueensRelativeCostStrategy::NQueensRelativeCostStrategy(int n)
    : N(n),
      nq_str(make_shared<NQueensCostStructure>(n))
{}

void NQueensRelativeCostStrategy::initializeCostData(vector<int> _configuration, int initial_cost)
{
    nq_str->set(_configuration);
    if(initial_cost != nq_str->CurrentCost)
        throw "(POSL Exception) Not matching costs (NQueensRelativeCostStrategy::initializeCostData)";
}

void NQueensRelativeCostStrategy::updateConfiguration(vector<int> new_config)
{
    T_Changes changes = Tools::GetChanges(nq_str->Configuration, new_config);
    if(changes.dim > 0)
        relative_cost(new_config, changes, true);
}

int NQueensRelativeCostStrategy::relative_cost(vector<int> new_config, T_Changes change, bool updating)
{
    return nq_str ->relative_cost(new_config, change, updating);
}


int NQueensRelativeCostStrategy::relativeSolutionCost(vector<int> _configuration)
{
    T_Changes changes = Tools::GetChanges(nq_str->Configuration, _configuration);
    return relativeSolutionCost(_configuration, changes);
}

int NQueensRelativeCostStrategy::relativeSolutionCost(std::vector<int> new_config, T_Changes change)
{
    return relative_cost(new_config, change, false);
}

int NQueensRelativeCostStrategy::costOnVariable(int i)
{
    nq_str->costOnVariable(i);
}
