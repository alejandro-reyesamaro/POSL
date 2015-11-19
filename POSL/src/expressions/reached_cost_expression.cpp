#include "reached_cost_expression.h"
#include "../tools/tools.h"

using namespace std;

#define MAX_ITER 1000

ReachedCostExpression::ReachedCostExpression(int _cost)
    : cost(_cost)
{}

bool ReachedCostExpression::evaluate(shared_ptr<PSP> psp)
{
    int costsofar = psp->BestCostSoFar();
    if(costsofar < 0)
        costsofar = cost + 1; // making true the expression
    return ( costsofar > cost );//( iterations < max_iter && costsofar > cost );
}

string ReachedCostExpression::codeToSend()
{
    return string(BE_REACHED_COST_TOK) + " " + Tools::int2str(cost); // + " " + Tools::int2str(max_iter);
}
