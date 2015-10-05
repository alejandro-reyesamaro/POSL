#include "same_cost_iterations_bound_expression.h"
#include "../tools/tools.h"

using namespace std;

#define MAX_ITER 1000

SameCostIterationsBoundExpression::SameCostIterationsBoundExpression(int _max_iterations)
    : max_iter(_max_iterations),
      iterations(0),
      cost(0)
{}

bool SameCostIterationsBoundExpression::evaluate(shared_ptr<PSP> psp)
{
    int current_cost = psp->CurrentCost();
    if(current_cost != cost)
    {
        cost = current_cost;
        iterations = 0;
    }
    else iterations ++;
    bool iter = iterations < max_iter;
    //if (!iter) iterations = 0;
    return ( iter );
}

string SameCostIterationsBoundExpression::codeToSend()
{
    return "b4 " + Tools::int2str(max_iter); // + " " + Tools::int2str(max_iter);
}
