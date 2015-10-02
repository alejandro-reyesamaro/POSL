#include "golomb_ruler.h"
#include "../data/dStrategy/factory_n_int_domain.h"
#include "cost_strategy/golomb_ruler_distances_cost_strategy.h"
#include "show_strategy/golomb_ruler_default_show_strategy.h"
#include "relative_cost_strategy/golomb_ruler_relative_cost_strategy.h"
#include "../tools/tools.h"

using namespace std;

GolombRuler::GolombRuler(int _order, int _length)
    : Benchmark(vector<Domain>(_order, Domain(make_shared<Factory_NIntDomain>(0, _length))),
                make_shared<GolombRulerDistancesCostStrategy>(_order, _length),
                make_shared<GolombRulerRelativeCostStrategy>(),
                make_shared<GolombRulerDefaultShowStrategy>(_order, _length)),
      order(_order),
      length(_length)
{}

string GolombRuler::showInstance()
{
    string out =  "Golob Ruler: order-" + Tools::int2str(order);
           out += ", length-" + Tools::int2str(length) + "\n";
    return out;
}
