#include "bool_expression_and_uncoder.h"
#include "../tools/coding_tools.h"
#include "../expressions/and_expression.h"
#include "boolean_expression_uncoder.h"

using namespace std;

BoolExpressionAndUncoder::BoolExpressionAndUncoder()
{
}

shared_ptr<BooleanExpression> BoolExpressionAndUncoder::uncode(string code)
{
    /*
    std::size_t pos_open = code.find_first_of("(");
    std::size_t pos_close = code.find_first_of(",");
    string be1_code = code.substr(pos_open + 1, pos_close - pos_open - 1);
    string rest = code.substr(pos_close + 1);
    Tools::trim(rest);
    pos_close = rest.find_first_of(")");
    string be2_code = rest.substr(0, pos_close);
    */

    pair<string, string> p = CodingTools::extractExpressionsCommaSeparated(code);
    BooleanExpressionUncoder be_unc;
    return make_shared<AndExpression>(be_unc.uncode(p.first), be_unc.uncode(p.second));
}
