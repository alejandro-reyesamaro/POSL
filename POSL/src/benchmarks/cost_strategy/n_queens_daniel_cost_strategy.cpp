#include "n_queens_daniel_cost_strategy.h"

#include <algorithm>

using namespace std;

NQueensDanielCostStrategy::NQueensDanielCostStrategy(int n)
    : N(n),
      nq_str(make_shared<NQueensCostStructure>(n))
{}

int NQueensDanielCostStrategy::solutionCost(std::vector<int> configuration)
{
    nq_str->set(configuration);
    return nq_str->CurrentCost;
}
