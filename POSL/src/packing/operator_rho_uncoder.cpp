#include "operator_rho_uncoder.h"
#include "../tools/tools.h"
#include "../tools/coding_tools.h"
#include "compound_module_uncoder.h"
#include "../operators/rho_operator.h"

using namespace std;

OperatorRhoUncoder::OperatorRhoUncoder()
{
}

shared_ptr<Operator> OperatorRhoUncoder::uncode(string code,
                                                shared_ptr<Benchmark> bench,
                                                shared_ptr<SearchProcessParamsStruct> psp_params)
{
    /*
    std::size_t pos_open = code.find_first_of("(");
    std::size_t pos_close = code.find_first_of(")");
    string str_param = code.substr(pos_open + 1, pos_close - pos_open - 1);
    Tools::trim(str_param);
    float param = Tools::str2float(str_param);
    string rest = code.substr(pos_close + 1);
    Tools::trim(rest);
    string cm1_code = Tools::frontModule(rest);
    int sizefront = cm1_code.size();
    rest = rest.substr(sizefront);
    Tools::trim(rest);
    string cm2_code = Tools::frontModule(rest);
    */

    //pair<string, pair<string, string>> p = CodingTools::extractExpressionAndCode2(code);
    pair<string, string> p = CodingTools::extractInnerCode(code, "(", ")", true, true);
    float param = Tools::str2float(p.first);

    pair<string, string> pm = CodingTools::separateModules(p.second, 2);
    string cm1_code = pm.first;
    string cm2_code = pm.second;

    CompoundModuleUncoder cm_unc;
    return make_shared<RhoOperator>(cm_unc.uncode(cm1_code, bench, psp_params), cm_unc.uncode(cm2_code, bench, psp_params), param);
}
