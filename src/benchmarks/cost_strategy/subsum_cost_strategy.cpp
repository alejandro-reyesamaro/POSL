#include "subsum_cost_strategy.h"

using namespace std;

SubsumCostStrategy::SubsumCostStrategy(vector<int> values, int subsum, int n)
    : cost_structure(make_shared<SubsumCostStructure>(values, subsum, n))
{}

int SubsumCostStrategy::solutionCost(std::vector<int> & configuration)
{
    cost_structure->init(configuration);
    return cost_structure->CurrentCost;
}
