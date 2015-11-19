#include "operator_conditional_uncoder.h"
#include "../tools/tools.h"
#include "compound_module_uncoder.h"
#include "../operators/conditional_operator.h"
#include "../packing/boolean_expression_uncoder.h"

using namespace std;

OperatorConditionalUncoder::OperatorConditionalUncoder()
{}

shared_ptr<Operator> OperatorConditionalUncoder::uncode(string code, shared_ptr<Benchmark> bench)
{
    std::size_t pos_open = code.find_first_of("(");
    std::size_t pos_close = code.find_first_of(")");
    string be_code = code.substr(pos_open + 1, pos_close - pos_open - 1);
    string rest = code.substr(pos_close + 1);
    Tools::trim(rest);
    string cm1_code = Tools::frontModule(rest);
    int sizefront = cm1_code.size();
    rest = rest.substr(sizefront);
    Tools::trim(rest);
    string cm2_code = Tools::frontModule(rest);

    CompoundModuleUncoder cm_unc;
    BooleanExpressionUncoder be_unc;
    return make_shared<ConditionalOperator>(cm_unc.uncode(cm1_code, bench),
                                            cm_unc.uncode(cm2_code, bench),
                                            be_unc.uncode(be_code));
}
