#include "uncode_rho_operator_strategy.h"
#include "uncode_compound_module_strategy.h"
#include "../tools/tools.h"

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
    string cm1_code = Tools::frontModule(rest);
    int sizefront = cm1_code.size();
    rest = rest.substr(sizefront);
    trim(rest);
    string cm2_code = Tools::frontModule(rest);

    UncodeCompoundModuleStrategy * CM_strategy = new UncodeCompoundModuleStrategy();
    return new RhoOperator(CM_strategy->uncode(cm1_code), CM_strategy->uncode(cm2_code), param);
}
