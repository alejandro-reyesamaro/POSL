#include "uncode_compound_module_strategy.h"

#include <boost/algorithm/string.hpp>
using namespace boost;

UncodeCompoundModuleStrategy::UncodeCompoundModuleStrategy()    
{}

CompoundModule * UncodeCompoundModuleStrategy::uncode(string code)
{
    trim(code);
    char front = code.front();
    char back  = code.back();
    string sub_code = code.substr(1, code.size() - 2);

    // GROUPERS ---- '{.}': sequential, '[.]': parallel
    if (front == '{' && back == '}')
    {
        UncodeSequentialGrouperStrategy * SG_strategy = new UncodeSequentialGrouperStrategy();
        return SG_strategy->uncode(sub_code);
    }
    else if (front == '[' && back == ']')
    {
        UncodeParallelGrouperStrategy * PG_strategy = new UncodeParallelGrouperStrategy();
        return PG_strategy->uncode(sub_code);
    }
    else
    {
        UncodeOperationModuleStrategy * OM_strategy = new UncodeOperationModuleStrategy();
        return OM_strategy->uncode(code);
    }
}
