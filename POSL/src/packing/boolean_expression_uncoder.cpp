#include "boolean_expression_uncoder.h"
#include "../tools/tools.h"

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
    Tools::trim(code);
    int pos_point = code.find('.');
    string op_name = code.substr(pos_point + 1, code.find(' ') - pos_point + 1);
    size_t pos_space = code.find_first_of(" ");
    string rest = code.substr(pos_space);
    Tools::trim(rest);

    if(op_name == "AND")
    {
        BoolExpressionAndUncoder be_and_unc;
        return be_and_unc.uncode(code);
    }
    else if(op_name == "OR")
    {
        BoolExpressionOrUncoder be_or_unc;
        return be_or_unc.uncode(code);
    }
    else
    {
        int param = Tools::str2int(rest);
        if(op_name == BE_ITERATION_BOUND_TOK)
            return make_shared<IteretionBoundExpression>(param);
        else if(op_name == BE_LOOP_BOUND_TOK)
            return make_shared<LoopBoundExpression>(param);
        else if(op_name == BE_REACHED_COST_TOK)
            return make_shared<ReachedCostExpression>(param);
        else if(op_name == BE_SAME_COST_ITERATIONS_TOK)
            return make_shared<SameCostIterationsBoundExpression>(param);
        else
            throw "(POSL Exception) Not well coded BooleanExpression (BooleanExpressionUncoder::uncode)";
    }
}
