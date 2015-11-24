#include "operator_conditional_uncoder.h"
#include "../tools/coding_tools.h"
#include "compound_module_uncoder.h"
#include "../operators/conditional_operator.h"
#include "../packing/boolean_expression_uncoder.h"

using namespace std;

OperatorConditionalUncoder::OperatorConditionalUncoder()
{}

shared_ptr<Operator> OperatorConditionalUncoder::uncode(string code, shared_ptr<Benchmark> bench)
{
    pair<string, pair<string, string>> p = CodingTools::extractExpressionAndCode2(code);

    string be_code = p.first;
    string cm1_code = p.second.first;
    string cm2_code = p.second.second;

    CompoundModuleUncoder cm_unc;
    BooleanExpressionUncoder be_unc;
    return make_shared<ConditionalOperator>(cm_unc.uncode(cm1_code, bench),
                                            cm_unc.uncode(cm2_code, bench),
                                            be_unc.uncode(be_code));
}
