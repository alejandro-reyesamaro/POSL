#include "bool_expression_or_uncoder.h"
#include "../tools/tools.h"
#include "../expressions/or_expression.h"
#include "boolean_expression_uncoder.h"

using namespace std;

BoolExpressionOrUncoder::BoolExpressionOrUncoder()
{
}

shared_ptr<BooleanExpression> BoolExpressionOrUncoder::uncode(string code)
{
    std::size_t pos_open = code.find_first_of("(");
    std::size_t pos_close = code.find_first_of(",");
    string be1_code = code.substr(pos_open + 1, pos_close - pos_open - 1);
    string rest = code.substr(pos_close + 1);
    Tools::trim(rest);
    pos_close = rest.find_first_of(")");
    string be2_code = rest.substr(0, pos_close);

    BooleanExpressionUncoder be_unc;
    return make_shared<OrExpression>(be_unc.uncode(be1_code), be_unc.uncode(be2_code));
}
