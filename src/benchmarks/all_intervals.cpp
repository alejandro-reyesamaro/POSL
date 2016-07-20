#include "all_intervals.h"
#include "../tools/tools.h"
#include "../data/dStrategy/factory_n_int_domain.h"
#include "show_strategy/all_interval_default_show_strategy.h"
#include "cost_strategy/all_intervals_daniel_cost_strategy.h"
#include "../data/uniform_domain.h"

#include <vector>
#include <iostream>

using namespace std;

AllIntervals::AllIntervals(int _n)
    : Benchmark(_n,
                make_shared<UniformDomain>(0, _n-1),
                make_shared<AllIntervalsDanielCostStrategy>(_n),
                make_shared<AllIntervalRelativeCostStrategy>(_n),
                make_shared<AllIntervalDefaultShowStrategy>(_n)
               ),
      n(_n)
{}

string AllIntervals::showInstance()
{
    string out =  "All-Intervals Series: n = " + Tools::int2str(n);
    return out;
}

std::shared_ptr<AllIntervalRelativeCostStrategy> AllIntervals::cast_my_relative_strategy()
{
    return static_pointer_cast<AllIntervalRelativeCostStrategy>(relative_cost_strategy);
}

vector<int> AllIntervals::Reset()
{
    return cast_my_relative_strategy()->Reset();
}
