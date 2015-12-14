#include "costas_array.h"
#include "../tools/tools.h"
#include "../data/dStrategy/factory_n_int_domain.h"
#include "cost_strategy/costas_array_relative_cost_strategy.h"
#include "show_strategy/costas_array_default_show_strategy.h"
#include "cost_strategy/costas_array_daniel_cost_strategy.h"

#include <vector>
#include <iostream>

using namespace std;

CostasArray::CostasArray(int _n)
    : Benchmark(vector<Domain>(_n, Domain(make_shared<Factory_NIntDomain>(0, _n-1))),
                make_shared<CostasArrayDanielCostStrategy>(_n),
                make_shared<CostasArrayRelativeCostStrategy>(_n),
                make_shared<CostasArrayDefaultShowStrategy>(_n)),
      n(_n)
{}

string CostasArray::showInstance()
{
    string out =  "Costas Array: n = " + Tools::int2str(n);
    return out;
}
