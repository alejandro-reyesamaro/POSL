#include "operator_rho_uncoder.h"
#include "../tools/tools.h"
#include "compound_module_uncoder.h"
#include "../operators/rho_operator.h"

using namespace std;

OperatorRhoUncoder::OperatorRhoUncoder()
{
}

shared_ptr<Operator> OperatorRhoUncoder::uncode(string code, shared_ptr<Benchmark> bench)
{
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

    CompoundModuleUncoder cm_unc;
    return make_shared<RhoOperator>(cm_unc.uncode(cm1_code, bench), cm_unc.uncode(cm2_code, bench), param);
}
