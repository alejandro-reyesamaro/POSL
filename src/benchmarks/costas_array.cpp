#include "costas_array.h"
#include "../tools/tools.h"
#include "../data/dStrategy/factory_n_int_domain.h"
#include "show_strategy/costas_array_default_show_strategy.h"
#include "cost_strategy/costas_array_daniel_cost_strategy.h"
#include "../data/uniform_domain.h"

#include <vector>
#include <iostream>

using namespace std;

CostasArray::CostasArray(int _n)
    : Benchmark(_n,
                make_shared<UniformDomain>(1, _n),
                make_shared<CostasArrayDanielCostStrategy>(_n),
                make_shared<CostasArrayRelativeCostStrategy>(_n),
                make_shared<CostasArrayDefaultShowStrategy>(_n)
               ),
      n(_n)
{}

string CostasArray::showInstance()
{
    string out =  "Costas Array: n = " + Tools::int2str(n);
    return out;
}

shared_ptr<CostasArrayRelativeCostStrategy> CostasArray::cast_my_relative_strategy()
{
    return static_pointer_cast<CostasArrayRelativeCostStrategy>(relative_cost_strategy);
}

vector<int> CostasArray::Reset()
{
    return cast_my_relative_strategy()->Reset();
}
