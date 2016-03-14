#include "n_queens_relative_cost_strategy.h"
#include "../../tools/tools.h"

#include <iostream>
#include <algorithm>

using namespace std;

NQueensRelativeCostStrategy::NQueensRelativeCostStrategy(int n)
    : N(n),
      nq_str(make_shared<NQueensCostStructure>(n)),
      bad_variables(n)
{}

void NQueensRelativeCostStrategy::initializeCostData(std::vector<int> &_configuration, int initial_cost)
{
    nq_str->set(_configuration);
    if(initial_cost != nq_str->CurrentCost)
        throw "(POSL Exception) Not matching costs (NQueensRelativeCostStrategy::initializeCostData)";
}

void NQueensRelativeCostStrategy::updateConfiguration(std::vector<int> &new_config)
{
    T_Changes changes = Tools::GetChanges(nq_str->Configuration, new_config);
    if(changes.dim > 0)
        relative_cost(new_config, changes, true);
}

int NQueensRelativeCostStrategy::relative_cost(std::vector<int> &new_config, T_Changes change, bool updating)
{
    return nq_str ->relative_cost(new_config, change, updating);
}

int NQueensRelativeCostStrategy::relativeSolutionCost(std::vector<int> &_configuration)
{
    T_Changes changes = Tools::GetChanges(nq_str->Configuration, _configuration);
    return relativeSolutionCost(_configuration, changes);
}

int NQueensRelativeCostStrategy::relativeSolutionCost(std::vector<int> &new_config, T_Changes change)
{
    return relative_cost(new_config, change, false);
}

int NQueensRelativeCostStrategy::costOnVariable(int i)
{
    return nq_str->costOnVariable(i);
}

int NQueensRelativeCostStrategy::sickestVariable()
{
    bad_variables.clear();
    int cov;
    int bcov = nq_str->costOnVariable(0);
    bad_variables.pushBack(0);
    for(int i = 1; i < N; i++)
    {
        cov = nq_str->costOnVariable(i);
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
