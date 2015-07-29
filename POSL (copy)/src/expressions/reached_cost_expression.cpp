#include "reached_cost_expression.h"
#include "../tools/tools.h"

#define MAX_ITER 2000

ReachedCostExpression::ReachedCostExpression(int _cost) : cost(_cost)
{}

bool ReachedCostExpression::evaluate(PSP * psp)
{
    int iterations = psp->GetIterations();
    int costsofar = psp->BestCostSoFar();
    return ( iterations <= MAX_ITER && costsofar > cost );
}

string ReachedCostExpression::codeToSend()
{
    return "b3 " + Tools::int2str(cost);
}
