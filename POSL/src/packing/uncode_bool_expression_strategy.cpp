#include "uncode_bool_expression_strategy.h"
#include "../tools/tools.h"

#include "../expressions/iteretion_bound_expression.h"
#include "../expressions/loop_bound_expression.h"
#include "../expressions/reached_cost_expression.h"

#include <boost/algorithm/string.hpp>
using namespace boost;

UncodeBoolExpressionStrategy::UncodeBoolExpressionStrategy()
{}

BooleanExpression * UncodeBoolExpressionStrategy::uncode(string code)
{
    trim(code);
    std::size_t pos_space = code.find_first_of(" ");
    string be_code = code.substr(0, pos_space);
    string rest = code.substr(pos_space);
    trim(rest);
    int param = Tools::str2int(rest);

    char L = be_code.front();
    int  N = Tools::str2int(be_code.substr(1));

    if(L == 'b')
    {
        switch(N)
        {
            case 1: // iteration bound
                return new IteretionBoundExpression(param);
                break;
            case 2: // loob bound
                return new LoopBoundExpression(param);
                break;
            case 3: // reached cost
                return new ReachedCostExpression(param);
                break;
            default:
                throw "Not well coded BooleanExpression";
        }
    }
    else
        throw "Not well coded BooleanExpression (ID)";
}
