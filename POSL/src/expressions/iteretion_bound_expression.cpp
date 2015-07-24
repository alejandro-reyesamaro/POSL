#include "iteretion_bound_expression.h"

IteretionBoundExpression::IteretionBoundExpression(int _max_iterations) : max_iterations(_max_iterations)
{}

bool IteretionBoundExpression::evaluate(PSP *psp)
{
    return psp->GetIterations() <= max_iterations;
}

string IteretionBoundExpression::codeToSend()
{
    return "b1 " + max_iterations;
}
