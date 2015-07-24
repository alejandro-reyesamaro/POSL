#include "uncode_rho_operator_strategy.h"
#include "uncode_compound_module_strategy.h"
#include "../tools/tools.h"

#include <boost/algorithm/string.hpp>

using namespace boost;

UncodeRhoOperatorStrategy::UncodeRhoOperatorStrategy()
{}

RhoOperator * UncodeRhoOperatorStrategy::uncode(string code)
{
    std::size_t pos_open = code.find_first_of("(");
    std::size_t pos_close = code.find_first_of(")");
    string str_param = code.substr(pos_open + 1, pos_close - pos_open - 1);
    trim(str_param);
    float param = Tools::str2float(str_param);
    string rest = code.substr(pos_close + 1);
    trim(rest);
    std::size_t pos_space = code.find_first_of(" ");
    string CM1_code = rest.substr(0, pos_space);
    string CM2_code = rest.substr(pos_space + 1);
    trim(CM2_code);

    UncodeCompoundModuleStrategy * CM_strategy = new UncodeCompoundModuleStrategy();
    return new RhoOperator(CM_strategy->uncode(CM1_code), CM_strategy->uncode(CM1_code), param);
}
