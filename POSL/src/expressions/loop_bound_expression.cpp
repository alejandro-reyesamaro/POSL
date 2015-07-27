#include "loop_bound_expression.h"
#include "../tools/tools.h"

LoopBoundExpression::LoopBoundExpression(int _max_loops) : loop(0), max_loops(_max_loops)
{}

bool LoopBoundExpression::evaluate(PSP * psp)
{
    loop ++;
    return loop <= max_loops;
}

string LoopBoundExpression::codeToSend()
{
    return "b2 " + Tools::int2str(max_loops);
}
