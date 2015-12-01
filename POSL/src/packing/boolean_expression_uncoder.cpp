#include "boolean_expression_uncoder.h"
#include "../tools/coding_tools.h"
#include "../tools/tools.h"
#include "../tools/tokens_definition.h"

#include "../expressions/iteretion_bound_expression.h"
#include "../expressions/reached_cost_expression.h"
#include "../expressions/loop_bound_expression.h"
#include "../expressions/same_cost_iterations_bound_expression.h"

#include "bool_expression_and_uncoder.h"
#include "bool_expression_or_uncoder.h"

using namespace std;

BooleanExpressionUncoder::BooleanExpressionUncoder()
{
}

shared_ptr<BooleanExpression> BooleanExpressionUncoder::uncode(string code)
{
    //pair<string, string> p = CodingTools::decouplingNameCodeFromBE(code);
    pair<pair<string, string>, string> p_tnm = CodingTools::separateTokenAndCode(code);

    string op_name = p_tnm.first.second;

    if(op_name == BE_AND_TOK_NAME)
    {
        BoolExpressionAndUncoder be_and_unc;
        return be_and_unc.uncode(code);
    }
    else if(op_name == BE_OR_TOK_NAME)
    {
        BoolExpressionOrUncoder be_or_unc;
        return be_or_unc.uncode(code);
    }
    else
    {
        string str_param = p_tnm.second;
        CodingTools::trim(str_param);
        int param = Tools::str2int(str_param);
        if(op_name == BE_ITERATION_BOUND_TOK_NAME)
            return make_shared<IteretionBoundExpression>(param);
        else if(op_name == BE_LOOP_BOUND_TOK_NAME)
            return make_shared<LoopBoundExpression>(param);
        else if(op_name == BE_REACHED_COST_TOK_NAME)
            return make_shared<ReachedCostExpression>(param);
        else if(op_name == BE_SAME_COST_ITERATIONS_TOK_NAME)
            return make_shared<SameCostIterationsBoundExpression>(param);
        else
            throw "(POSL Exception) Not well coded BooleanExpression (BooleanExpressionUncoder::uncode)";
    }
}
