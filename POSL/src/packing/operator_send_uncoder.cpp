#include "operator_send_uncoder.h"
#include "../tools/coding_tools.h"
#include "compound_module_uncoder.h"
#include "../operators/send_data_operator.h"

using namespace std;

OperatorSendUncoder::OperatorSendUncoder()
{
}

shared_ptr<Operator> OperatorSendUncoder::uncode(string code, shared_ptr<Benchmark> bench)
{
    /*
    std::size_t pos_open = code.find_first_of("(");
    std::size_t pos_close = code.find_first_of(")");
    string name = code.substr(pos_open + 1, pos_close - pos_open - 1);
    string cm_code = code.substr(pos_close + 1);
    */

    //pair<string, string> p = CodingTools::extractExpressionAndCode1(code);
    pair<string, string> p = CodingTools::extractInnerCode(code, "(", ")", true, true);

    string name = p.first;
    string cm_code = p.second;

    CompoundModuleUncoder cm_unc;
    return make_shared<SendDataOperator>(name, cm_unc.uncode(cm_code, bench));
}
