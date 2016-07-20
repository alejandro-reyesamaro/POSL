#include "operator_flo_uncoder.h"
#include "../tools/coding_tools.h"
#include "../tools/tools.h"
#include "compound_module_uncoder.h"
#include "../operators/florian_operator.h"

using namespace std;

OperatorFloUncoder::OperatorFloUncoder()
{
}

shared_ptr<Operator> OperatorFloUncoder::uncode(string code,
                                                shared_ptr<Benchmark> bench,
                                                shared_ptr<SearchProcessParamsStruct> psp_params)
{
    /*
    std::size_t pos_open = code.find_first_of("(");
    std::size_t pos_close = code.find_first_of(")");
    string times = code.substr(pos_open + 1, pos_close - pos_open - 1);
    string cm_code = code.substr(pos_close + 1);
    */

    //pair<string, string> p = CodingTools::extractExpressionAndCode1(code);
    pair<string, string> p = CodingTools::extractInnerCode(code, "(", ")", true, true);
    int param = Tools::str2int(p.first);
    string cm_code = p.second;
    //CodingTools::trim(cm_code);

    CompoundModuleUncoder cm_unc;
    return make_shared<FlorianOperator>(param, cm_unc.uncode(cm_code, bench, psp_params));
}
