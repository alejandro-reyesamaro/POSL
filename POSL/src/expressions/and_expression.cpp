#include "and_expression.h"

using namespace std;

AndExpression::AndExpression(shared_ptr<BooleanExpression> _ex1, shared_ptr<BooleanExpression> _ex2)
    : ex1(_ex1),
      ex2(_ex2)
{}

bool AndExpression::evaluate(shared_ptr<PSP> psp)
{
    return ( ex1->evaluate(psp) && ex2->evaluate(psp) );
}

string AndExpression::codeToSend()
{
    return string(BE_AND_TOK) + " (" + ex1->codeToSend() + ", " + ex2->codeToSend() + ")";
}
