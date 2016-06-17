#include "operator_conditional_uncoder.h"
#include "../tools/coding_tools.h"
#include "compound_module_uncoder.h"
#include "../operators/conditional_operator.h"
#include "../packing/boolean_expression_uncoder.h"

using namespace std;

OperatorConditionalUncoder::OperatorConditionalUncoder()
{}

shared_ptr<Operator> OperatorConditionalUncoder::uncode(string code,
                                                        shared_ptr<Benchmark> bench,
                                                        shared_ptr<SearchProcessParamsStruct> psp_params)
{
    //pair<string, pair<string, string>> p = CodingTools::extractExpressionAndCode2(code);

    pair<string, string> p = CodingTools::extractInnerCode(code, "(", ")", true, true);
    string be_code = p.first;

    pair<string, string> pm = CodingTools::separateModules(p.second, 2);

    string cm1_code = pm.first;
    string cm2_code = pm.second;

    CompoundModuleUncoder cm_unc;
    BooleanExpressionUncoder be_unc;
    return make_shared<ConditionalOperator>(cm_unc.uncode(cm1_code, bench, psp_params),
                                            cm_unc.uncode(cm2_code, bench, psp_params),
                                            be_unc.uncode(be_code));
}
