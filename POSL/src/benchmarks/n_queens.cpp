#include "n_queens.h"
#include "../tools/tools.h"
#include "../data/dStrategy/factory_n_int_domain.h"
#include "cost_strategy/n_queens_daniel_cost_strategy.h"
#include "show_strategy/n_queens_default_show_strategy.h"
#include "cost_strategy/n_queens_relative_cost_strategy.h"

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

NQueens::NQueens(int n)
    : Benchmark(vector<Domain>(n, Domain(std::make_shared<Factory_NIntDomain>(0, n-1))),
                make_shared<NQueensDanielCostStrategy>(n),
                make_shared<NQueensRelativeCostStrategy>(n),
                make_shared<NQueensDefaultShowStrategy>(n)),
      N(n)
{}

string NQueens::showInstance()
{
    return "N Queens: N = " + Tools::int2str(N) + "\n";
}
