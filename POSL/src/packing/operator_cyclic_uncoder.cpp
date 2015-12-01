#include "operator_cyclic_uncoder.h"
#include "../tools/coding_tools.h"
#include "compound_module_uncoder.h"
#include "../operators/cyclic_operator.h"
#include "../packing/boolean_expression_uncoder.h"

using namespace std;

OperatorCyclicUncoder::OperatorCyclicUncoder()
{
}

shared_ptr<Operator> OperatorCyclicUncoder::uncode(string code, shared_ptr<Benchmark> bench)
{
    //std::size_t pos_open = code.find_first_of("(");
    //std::size_t pos_close = code.find_first_of(")");
    //pair<string, string> p = CodingTools::extractExpressionAndCode1(code);
    pair<string, string> p = CodingTools::extractInnerCode(code, "(", ")", true, true);
    string be_code = p.first;
    string cm_code = p.second;
    //CodingTools::trim(cm_code);

    CompoundModuleUncoder cm_unc;
    BooleanExpressionUncoder be_unc;
    return make_shared<CyclicOperator>(cm_unc.uncode(cm_code, bench), be_unc.uncode(be_code));
}
