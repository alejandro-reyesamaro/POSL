#include "golomb_ruler.h"
#include "../data/dStrategy/factory_n_int_domain.h"
#include "cost_strategy/golomb_ruler_distances_cost_strategy.h"
#include "cost_strategy/golomb_ruler_max_possible_distances_cost_strategy.h"
#include "show_strategy/golomb_ruler_default_show_strategy.h"
#include "cost_strategy/golomb_ruler_relative_cost_strategy.h"
#include "../tools/tools.h"
#include "../data/uniform_domain.h"

using namespace std;

#define MAX_VAL_GR_DOMAIN ( _length - ( (_order - 2) * (_order - 1) ) / 2 )

GolombRuler::GolombRuler(int _order, int _length)
    : Benchmark(_order,
                //make_shared<UniformDomain>(0, _length), // UNCOMENT for the previews version of modelization
                make_shared<UniformDomain>(1, MAX_VAL_GR_DOMAIN), // NEW VERSION modelization
                make_shared<GolombRulerMaxPossibleDistancesCostStrategy>(_order, _length),
                make_shared<GolombRulerRelativeCostStrategy>(_order, _length),
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
