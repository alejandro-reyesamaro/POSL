#include "uncode_conditional_operator_strategy.h"
#include "../tools/tools.h"

UncodeConditionalOperatorStrategy::UncodeConditionalOperatorStrategy()
    : CM_strategy(new UncodeCompoundModuleStrategy()),
      BE_strategy(new UncodeBoolExpressionStrategy())
{}

ConditionalOperator * UncodeConditionalOperatorStrategy::uncode(string code, Benchmark * bench)
{
    std::size_t pos_open = code.find_first_of("(");
    std::size_t pos_close = code.find_first_of(")");
    string be_code = code.substr(pos_open + 1, pos_close - pos_open - 1);
    string rest = code.substr(pos_close + 1);
    trim(rest);
    string cm1_code = Tools::frontModule(rest);
    int sizefront = cm1_code.size();
    rest = rest.substr(sizefront);
    trim(rest);
    string cm2_code = Tools::frontModule(rest);

    return new ConditionalOperator(CM_strategy->uncode(cm1_code, bench), CM_strategy->uncode(cm2_code, bench), BE_strategy->uncode(be_code));
}
