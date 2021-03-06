#include "iteretion_bound_expression.h"
#include "../tools/tools.h"
#include "../tools/tokens_definition.h"

using namespace std;

IteretionBoundExpression::IteretionBoundExpression(int _max_iterations)
    : max_iterations(_max_iterations)
{}

bool IteretionBoundExpression::evaluate(shared_ptr<PSP> psp)
{
    int costsofar = psp->BestCostSoFar();
    if(costsofar < 0)
        costsofar = 1; // making true the second expression
    return (psp->GetIterations() <= max_iterations && costsofar > 0);
}

string IteretionBoundExpression::codeToSend()
{
    return string(BE_ITERATION_BOUND_TOK) + " " + Tools::int2str(max_iterations);
}
