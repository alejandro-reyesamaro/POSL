#include "uncode_conditional_operator_strategy.h"
#include "uncode_compound_module_strategy.h"
#include "uncode_bool_expression_strategy.h"
#include "../tools/tools.h"

UncodeConditionalOperatorStrategy::UncodeConditionalOperatorStrategy()
{}

ConditionalOperator * UncodeConditionalOperatorStrategy::uncode(string code)
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

    UncodeCompoundModuleStrategy * CM_strategy = new UncodeCompoundModuleStrategy();
    UncodeBoolExpressionStrategy * BE_strategy = new UncodeBoolExpressionStrategy();
    return new ConditionalOperator(CM_strategy->uncode(cm1_code), CM_strategy->uncode(cm2_code), BE_strategy->uncode(be_code));
}