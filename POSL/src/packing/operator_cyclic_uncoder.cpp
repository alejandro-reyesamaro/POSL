#include "operator_cyclic_uncoder.h"
#include "../tools/tools.h"
#include "compound_module_uncoder.h"
#include "../operators/cyclic_operator.h"
#include "../packing/boolean_expression_uncoder.h"

using namespace std;

OperatorCyclicUncoder::OperatorCyclicUncoder()
{
}

shared_ptr<Operator> OperatorCyclicUncoder::uncode(string code, shared_ptr<Benchmark> bench)
{
    std::size_t pos_open = code.find_first_of("(");
    std::size_t pos_close = code.find_first_of(")");
    string be_code = code.substr(pos_open + 1, pos_close - pos_open - 1);
    string cm_code = code.substr(pos_close + 1);

    CompoundModuleUncoder cm_unc;
    BooleanExpressionUncoder be_unc;
    return make_shared<CyclicOperator>(cm_unc.uncode(cm_code, bench), be_unc.uncode(be_code));
}
