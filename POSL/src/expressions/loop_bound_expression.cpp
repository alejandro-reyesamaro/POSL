#include "loop_bound_expression.h"

LoopBoundExpression::LoopBoundExpression(int _max_loops) : loop(0), max_loops(_max_loops)
{}

bool LoopBoundExpression::evaluate(PSP * psp)
{
    loop ++;
    return loop <= max_loops;
}

string LoopBoundExpression::codeToSend()
{
    return "b2 " + max_loops;
}
