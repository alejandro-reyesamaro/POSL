#include "costas_array_relative_cost_strategy.h"
#include "../../tools/tools.h"

#include <iostream>
#include <algorithm>

using namespace std;

CostasArrayRelativeCostStrategy::CostasArrayRelativeCostStrategy(int n)
    : N(n),
      ca_str(make_shared<CostasArrayCostStructure>(n)),
      bad_variables(n)
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

vector<int> CostasArrayRelativeCostStrategy::Reset()//vector<int> & current_configuration)
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
    bad_variables.clear();
    int cov;
    int bcov = ca_str->costOnVariable(0);
    bad_variables.pushBack(0);
    for(int i = 1; i < N; i++)
    {
        cov = ca_str->costOnVariable(i);
        if (cov == bcov)
            bad_variables.pushBack(i);
        else if(cov > bcov)
        {
            bcov = cov;
            bad_variables.clear();
            bad_variables.pushBack(i);
        }
    }
    return bad_variables.elementAt(ca_str->GetRandomized()->NextInt(0, bad_variables.size()-1));
}
