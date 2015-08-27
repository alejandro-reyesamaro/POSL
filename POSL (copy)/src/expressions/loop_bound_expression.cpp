#include "loop_bound_expression.h"
#include "../tools/tools.h"

LoopBoundExpression::LoopBoundExpression(int _max_loops) : loop(0), max_loops(_max_loops)
{}

bool LoopBoundExpression::evaluate(PSP * psp)
{
    loop ++;
    int costsofar = psp->BestCostSoFar();
    if(costsofar < 0)
        costsofar = 1; // making true the second expression
    if(loop > max_loops)
    {
        loop = 0;
        return false;
    }
    return (costsofar > 0);
}

string LoopBoundExpression::codeToSend()
{
    return "b2 " + Tools::int2str(max_loops);
}
