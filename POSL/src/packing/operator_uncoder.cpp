#include "operator_uncoder.h"
#include "../tools/coding_tools.h"

#include "operator_conditional_uncoder.h"
#include "operator_cyclic_uncoder.h"
#include "operator_flo_uncoder.h"
#include "operator_rho_uncoder.h"
#include "operator_send_uncoder.h"
#include "operator_tabu_uncoder.h"
#include "compound_module_uncoder.h"
#include "../tools/tokens_definition.h"

#include "../operators/sequential_exec_operator.h"
#include "../operators/speed_operator.h"
#include "../operators/union_operator.h"
#include "../operators/min_operator.h"
#include "../operators/not_null_operator.h"
#include "../operators/first_operator.h"

using namespace std;

OperatorUncoder::OperatorUncoder()
{
}

shared_ptr<Operator> OperatorUncoder::uncode(string code, shared_ptr<Benchmark> bench)
{
    pair<pair<string, string>, string> p_tnc = CodingTools::separateTokenAndCode(code);
    string op_name = p_tnc.first.second;

    if (op_name == OP_CONDITIONAL_EXECUTION_TOK_NAME)
    {
        OperatorConditionalUncoder op_cond_unc;
        return op_cond_unc.uncode(code, bench);
    }
    else if (op_name == OP_CYCLIC_TOK_NAME)
    {
        OperatorCyclicUncoder op_cyc_unc;
        return op_cyc_unc.uncode(code, bench);
    }
    else if (op_name == OP_PLORIAN_TOK_NAME)
    {
        OperatorFloUncoder op_flo_unc;
        return op_flo_unc.uncode(code, bench);
    }
    else if (op_name == OP_RHO_TOK_NAME)
    {
        OperatorRhoUncoder op_rho_unc;
        return op_rho_unc.uncode(code, bench);
    }
    else if (op_name == OP_SEND_DATA_TOK_NAME)
    {
        OperatorSendUncoder op_send_unc;
        return op_send_unc.uncode(code, bench);
    }
    else if (op_name == OP_TABU_TOK_NAME)
    {
        OperatorTabuUncoder op_tabu_unc;
        return op_tabu_unc.uncode(code, bench);
    }
    else
    {
        pair<string, string> p = CodingTools::separateModules(p_tnc.second, 2);
        string cm1_code = p.first;
        string cm2_code = p.second;

        CompoundModuleUncoder cm_unc;

        if (op_name == OP_MIN_TOK_NAME)
            return make_shared<MinOperator>(cm_unc.uncode(cm1_code, bench), cm_unc.uncode(cm2_code, bench));
        if (op_name == OP_NOTNULL_TOK_NAME)
            return make_shared<NotNullOperator>(cm_unc.uncode(cm1_code, bench), cm_unc.uncode(cm2_code, bench));
        if (op_name == OP_FIRST_TOK_NAME)
            return make_shared<FirstOperator>(cm_unc.uncode(cm1_code, bench), cm_unc.uncode(cm2_code, bench));
        else if (op_name == OP_SEQUENTIAL_EXECUTION_TOK_NAME)
            return make_shared<SequentialExecOperator>(cm_unc.uncode(cm1_code, bench), cm_unc.uncode(cm2_code, bench));
        else if (op_name == OP_SPEED_TOK_NAME)
            return make_shared<SpeedOperator>(cm_unc.uncode(cm1_code, bench), cm_unc.uncode(cm2_code, bench));
        else if (op_name == OP_UNION_TOK_NAME)
            return make_shared<UnionOperator>(cm_unc.uncode(cm1_code, bench), cm_unc.uncode(cm2_code, bench));
        else
            throw "(POSL Exception) Not well coded Binary Operator (OperatorUncoder::uncode)";
    }
}
