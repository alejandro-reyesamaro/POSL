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
            {
                //int param = Tools::str2int(rest);
                return new IteretionBoundExpression(param);
            }
            break;
            case 2: // loob bound
            {
                //int param = Tools::str2int(rest);
                return new LoopBoundExpression(param);
            }
            break;
            case 3: // reached cost
            {
                //std::size_t pos_2ndspace = rest.find_first_of(" ");
                //string cost = rest.substr(0, pos_2ndspace);
                //string max_time = code.substr(pos_2ndspace);
                //trim(final);
                //int param1 = Tools::str2int(cost);
                //int param2 = Tools::str2int(max_time);
                //return new ReachedCostExpression(param1, param2);
                return new ReachedCostExpression(param);
            }
            break;

            default:
                throw "(POSL Exception) Not well coded BooleanExpression";
        }
    }
    else
        throw "(POSL Exception) Not well coded BooleanExpression (ID)";
}
