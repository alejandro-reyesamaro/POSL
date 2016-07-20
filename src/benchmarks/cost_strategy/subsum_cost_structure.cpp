#include "subsum_cost_structure.h"
#include "../../tools/tools.h"

#include <algorithm>

using namespace std;

SubsumCostStructure::SubsumCostStructure(std::vector<int> values, int subsum, unsigned int n)
    : Subsum(subsum),
      N(n),
      CurrentCost(0),
      Configuration(values),
      current_sum(0)
{
    if(n >= values.size())
        throw "(POSL Exception) invalid value of N (SubsumCostStructure)";
}

int SubsumCostStructure::relative_cost(vector<int> &, T_Changes change, bool updating)
{
    int cost = 0, sum = current_sum;
    for(int i = 0; i < change.dim; i++)
    {
        if(change.positions[i] < N)
        {
            sum -= Configuration[change.positions[i]];
            sum += change.new_values[i];
        }
        if(updating) Configuration[change.positions[i]] = change.new_values[i];
    }
    cost = abs(Subsum - sum);
    if(updating)
    {
        current_sum = sum;
        CurrentCost = cost;
    }
    return cost;
}

void SubsumCostStructure::init(vector<int> config)
{
    Configuration = config;
    current_sum = Tools::sum(Configuration, N);
    CurrentCost = abs(Subsum - current_sum);
}

int SubsumCostStructure::costOnVariable(int)
{
    return 1; // default behavior
}

void SubsumCostStructure::reset(){}
