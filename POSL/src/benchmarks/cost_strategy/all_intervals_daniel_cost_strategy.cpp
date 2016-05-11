#include "all_intervals_daniel_cost_strategy.h"

#include <algorithm>

using namespace std;

AllIntervalsDanielCostStrategy::AllIntervalsDanielCostStrategy(int n)
    : cost_str(make_shared<CostasArrayCostStructure>(n))
{}

int AllIntervalsDanielCostStrategy::solutionCost(std::vector<int> & configuration)
{
    cost_str->init(configuration);
    return cost_str->CurrentCost;
}
