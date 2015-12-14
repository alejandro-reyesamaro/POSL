#include "costas_array_daniel_cost_strategy.h"

#include <algorithm>

using namespace std;

CostasArrayDanielCostStrategy::CostasArrayDanielCostStrategy(int n)
    : N(n),
      ca_str(make_shared<CostasArrayCostStructure>(n))
{}

int CostasArrayDanielCostStrategy::solutionCost(vector<int> configuration)
{
    ca_str->init(configuration);
    return ca_str->CurrentCost;
}
