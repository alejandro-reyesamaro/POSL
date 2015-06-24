#include "loop_bound_expression.h"

LoopBoundExpression::LoopBoundExpression(int _max_loops) : max_loops(_max_loops)
{}

bool LoopBoundExpression::evaluate(PSP * psp)
{
    return loop++ <= max_loops;
}
