#include "or_expression.h"

using namespace std;

OrExpression::OrExpression(shared_ptr<BooleanExpression> _ex1, shared_ptr<BooleanExpression> _ex2)
    : ex1(_ex1),
      ex2(_ex2)
{
}

bool OrExpression::evaluate(shared_ptr<PSP> psp)
{
    return ( ex1->evaluate(psp) ||ex2->evaluate(psp) );
}

string OrExpression::codeToSend()
{
    return "b5 ";
}
