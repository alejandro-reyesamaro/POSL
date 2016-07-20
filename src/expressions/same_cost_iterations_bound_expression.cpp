#include "same_cost_iterations_bound_expression.h"
#include "../tools/tools.h"
#include "../tools/tokens_definition.h"

#include <iostream>

using namespace std;

SameCostIterationsBoundExpression::SameCostIterationsBoundExpression(int _max_iterations)
    : max_iter(_max_iterations),
      iterations(0),
      cost(0),
      current_cost(0)
{}

bool SameCostIterationsBoundExpression::evaluate(shared_ptr<PSP> psp)
{
    current_cost = psp->CurrentCost();
    if(psp->CurrentCost() != cost)
    {
        cost = current_cost;
        iterations = 0;
    }
    else iterations ++;
    //bool iter = iterations < max_iter;
    //if (!iter) cout << "cambio" << endl;
    //cout << current_cost << endl;
    return ( iterations < max_iter && current_cost > 0);
}

string SameCostIterationsBoundExpression::codeToSend()
{
    return string(BE_SAME_COST_ITERATIONS_TOK) + " " + Tools::int2str(max_iter);
}
