#include "reached_cost_expression.h"
#include "../tools/tools.h"

#define MAX_ITER 1000

ReachedCostExpression::ReachedCostExpression(int _cost)
    : cost(_cost)
{}

bool ReachedCostExpression::evaluate(PSP * psp)
{
    int costsofar = psp->BestCostSoFar();
    if(costsofar < 0)
        costsofar = cost + 1; // making true the expression
    return ( costsofar > cost );//( iterations < max_iter && costsofar > cost );
}

string ReachedCostExpression::codeToSend()
{
    return "b3 " + Tools::int2str(cost); // + " " + Tools::int2str(max_iter);
}
