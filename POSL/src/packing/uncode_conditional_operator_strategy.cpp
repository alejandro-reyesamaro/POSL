#include "uncode_conditional_operator_strategy.h"
#include "uncode_compound_module_strategy.h"
#include "uncode_bool_expression_strategy.h"

#include <boost/algorithm/string.hpp>

using namespace boost;

UncodeConditionalOperatorStrategy::UncodeConditionalOperatorStrategy()
{}

ConditionalOperator * UncodeConditionalOperatorStrategy::uncode(string code)
{
    std::size_t pos_open = code.find_first_of("(");
    std::size_t pos_close = code.find_first_of(")");
    string be_code = code.substr(pos_open + 1, pos_close - pos_open - 1);
    string rest = code.substr(pos_close + 1);
    trim(rest);
    std::size_t pos_space = code.find_first_of(" ");
    string CM1_code = rest.substr(0, pos_space);
    string CM2_code = rest.substr(pos_space + 1);
    trim(CM2_code);

    UncodeCompoundModuleStrategy * CM_strategy = new UncodeCompoundModuleStrategy();
    UncodeBoolExpressionStrategy * BE_strategy = new UncodeBoolExpressionStrategy();
    return new ConditionalOperator(CM_strategy->uncode(CM1_code), CM_strategy->uncode(CM1_code), BE_strategy->uncode(be_code));
}
