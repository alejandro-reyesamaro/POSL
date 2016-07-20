#include "subsum.h"
#include "../data/dStrategy/factory_n_int_domain.h"
#include "cost_strategy/subsum_cost_strategy.h"
#include "show_strategy/subsum_show_strategy.h"
#include "cost_strategy/subsum_relative_cost_strategy.h"
#include "../tools/tools.h"
#include "../data/uniform_domain.h"

using namespace std;

Subsum::Subsum(std::vector<int> _values, int _subsum, int _n)
    : Benchmark(_values.size(),
                make_shared<UniformDomain>(Tools::min(_values), Tools::max(_values)),
                make_shared<SubsumCostStrategy>(_values, _subsum, _n),
                make_shared<SubsumRelativeCostStrategy>(_values, _subsum, _n),
                make_shared<SubsumShowStrategy>(_values, _n)),
      values(_values),
      subsum(_subsum),
      n(_n)
{}

string Subsum::showInstance()
{
    string out =  "Subsum of " + Tools::int2str(n);
           out += " integers, equals to " + Tools::int2str(subsum) + "\n";
    return out;
}
