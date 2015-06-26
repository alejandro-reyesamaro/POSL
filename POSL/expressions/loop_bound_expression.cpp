#include "loop_bound_expression.h"

LoopBoundExpression::LoopBoundExpression(int _max_loops) : max_loops(_max_loops), loop(0)
{}

bool LoopBoundExpression::evaluate(PSP * psp)
{
    loop ++;
    return loop <= max_loops;
}
