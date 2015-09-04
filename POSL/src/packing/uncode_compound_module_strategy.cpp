#include "uncode_compound_module_strategy.h"

#include <boost/algorithm/string.hpp>
using namespace boost;

UncodeCompoundModuleStrategy::UncodeCompoundModuleStrategy()
    : SG_strategy(new UncodeSequentialGrouperStrategy()),
      PG_strategy(new UncodeParallelGrouperStrategy()),
      OM_strategy(new UncodeOperationModuleStrategy())
{}

CompoundModule * UncodeCompoundModuleStrategy::uncode(string code, Benchmark * bench)
{
    trim(code);
    char front = code.front();
    char back  = code.back();
    string sub_code = code.substr(1, code.size() - 2);

    // GROUPERS ---- '{.}': sequential, '[.]': parallel
    if (front == '{' && back == '}')
        return SG_strategy->uncode(sub_code, bench);
    else if (front == '[' && back == ']')
        return PG_strategy->uncode(sub_code, bench);
    else
        return OM_strategy->uncode(code, bench);
}
