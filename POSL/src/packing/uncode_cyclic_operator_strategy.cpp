#include "uncode_cyclic_operator_strategy.h"
#include "uncode_compound_module_strategy.h"

UncodeCyclicOperatorStrategy::UncodeCyclicOperatorStrategy()
    : //CM_strategy(new UncodeCompoundModuleStrategy()),
      BE_strategy(new UncodeBoolExpressionStrategy())
{}

CyclicOperator * UncodeCyclicOperatorStrategy::uncode(string code, Benchmark * bench)
{
    std::size_t pos_open = code.find_first_of("(");
    std::size_t pos_close = code.find_first_of(")");
    string be_code = code.substr(pos_open + 1, pos_close - pos_open - 1);
    string cm_code = code.substr(pos_close + 1);

    UncodeCompoundModuleStrategy * CM_strategy = new UncodeCompoundModuleStrategy();
    return new CyclicOperator(CM_strategy->uncode(cm_code, bench), BE_strategy->uncode(be_code));
}
