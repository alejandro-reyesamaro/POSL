#include "reached_cost_expression.h"
#include "../tools/tools.h"

ReachedCostExpression::ReachedCostExpression(int _cost) : cost(_cost)
{}

bool ReachedCostExpression::evaluate(PSP * psp)
{
    return (psp->CurrentCost() <= cost);
}

string ReachedCostExpression::codeToSend()
{
    return "b3 " + Tools::int2str(cost);
}
