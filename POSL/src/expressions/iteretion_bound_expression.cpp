#include "iteretion_bound_expression.h"

IteretionBoundExpression::IteretionBoundExpression(int _max_iterations) : max_iterations(_max_iterations)
{}

bool IteretionBoundExpression::evaluate(PSP *psp)
{
    return psp->GetIterations() <= max_iterations;
}
