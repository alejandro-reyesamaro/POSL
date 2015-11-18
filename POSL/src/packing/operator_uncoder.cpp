#include "operator_uncoder.h"
#include "../tools/tools.h"

#include "operator_conditional_uncoder.h"
#include "operator_cyclic_uncoder.h"
#include "operator_flo_uncoder.h"
#include "operator_rho_uncoder.h"
#include "operator_send_uncoder.h"
#include "compound_module_uncoder.h"

#include "../operators/sequential_exec_operator.h"
#include "../operators/speed_operator.h"
#include "../operators/union_operator.h"
#include "../operators/min_operator.h"

using namespace std;

OperatorUncoder::OperatorUncoder()
{
}

shared_ptr<Operator> OperatorUncoder::uncode(string code, shared_ptr<Benchmark> bench)
{
    Tools::trim(code);
    int pos_point = code.find('.');
    string op_name = code.substr(pos_point + 1, code.find(' ') - pos_point + 1);

    if (op_name == "?")
    {
        OperatorConditionalUncoder op_cond_unc;
        return op_cond_unc.uncode(code, bench);
    }
    else if (op_name == "Cyc")
    {
        OperatorCyclicUncoder op_cyc_unc;
        return op_cyc_unc.uncode(code, bench);
    }
    else if (op_name == "Flo")
    {
        OperatorFloUncoder op_flo_unc;
        return op_flo_unc.uncode(code, bench);
    }
    else if (op_name == "Rho")
    {
        OperatorRhoUncoder op_rho_unc;
        return op_rho_unc.uncode(code, bench);
    }
    else if (op_name == "Send")
    {
        OperatorSendUncoder op_send_unc;
        return op_send_unc.uncode(code, bench);
    }
    else
    {
        size_t pos_space = code.find_first_of(" ");
        string rest = code.substr(pos_space + 1);
        Tools::trim(rest);
        string cm1_code = Tools::frontModule(rest);
        int sizefront = cm1_code.size();
        rest = rest.substr(sizefront);
        Tools::trim(rest);
        string cm2_code = Tools::frontModule(rest);

        CompoundModuleUncoder cm_unc;

        if (op_name == "Min")
            return make_shared<MinOperator>(cm_unc.uncode(cm1_code, bench), cm_unc.uncode(cm2_code, bench));
        else if (op_name == "|->")
            return make_shared<SequentialExecOperator>(cm_unc.uncode(cm1_code, bench), cm_unc.uncode(cm2_code, bench));
        else if (op_name == "Speed")
            return make_shared<SpeedOperator>(cm_unc.uncode(cm1_code, bench), cm_unc.uncode(cm2_code, bench));
        else if (op_name == "U")
            return make_shared<UnionOperator>(cm_unc.uncode(cm1_code, bench), cm_unc.uncode(cm2_code, bench));
        else
            throw "Not well coded Binary Operator";
    }
}
