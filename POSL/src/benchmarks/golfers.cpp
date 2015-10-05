#include "golfers.h"
#include "../tools/tools.h"
#include "../data/dStrategy/factory_n_int_domain.h"
#include "cost_strategy/golfers_long_int_cost_strategy.h"
#include "show_strategy/golfers_default_show_strategy.h"
#include "relative_cost_strategy/golfers_relative_cost_strategy.h"

#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

#define PENALIZATION 10
#define TP players * groups

Golfers::Golfers(int g, int p, int w)
    : Benchmark(vector<Domain>(g * p * w, Domain(make_shared<Factory_NIntDomain>(1,p * g))),
                make_shared<GolfersLongIntCostStrategy>(g,p,w),
                make_shared<GolfersRelativeCostStrategy>(g,p,w),
                make_shared<GolfersDefaultShowStrategy>(g,p,w)),
      groups(g),
      players(p),
      weeks(w)
{}

string Golfers::showInstance()
{
    string out =  "Golfers: players-" + Tools::int2str(players);
           out += ", groups-" + Tools::int2str(groups);
           out += ", weeks-" + Tools::int2str(weeks) + "\n";
    return out;
}
