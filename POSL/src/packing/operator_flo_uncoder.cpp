#include "operator_flo_uncoder.h"
#include "../tools/tools.h"
#include "compound_module_uncoder.h"
#include "../operators/florian_operator.h"

using namespace std;

OperatorFloUncoder::OperatorFloUncoder()
{
}

shared_ptr<Operator> OperatorFloUncoder::uncode(string code, shared_ptr<Benchmark> bench)
{
    std::size_t pos_open = code.find_first_of("(");
    std::size_t pos_close = code.find_first_of(")");
    string times = code.substr(pos_open + 1, pos_close - pos_open - 1);
    string cm_code = code.substr(pos_close + 1);

    CompoundModuleUncoder cm_unc;
    return make_shared<FlorianOperator>(Tools::str2int(times), cm_unc.uncode(cm_code, bench));
}
