#include "cyclic_operator.h"
#include "strategy/cyclic_sequential_strategy.h"

#include <iostream>
using namespace std;

CyclicOperator::CyclicOperator(CompoundModule * _M1, BooleanExpression * _ex)
    : UnaryOperator(_M1, new CyclicSequentialStrategy(_M1, _ex)),
      ex(_ex)
{
    //cout << "Built CyclicOperator" << endl;
}

string CyclicOperator::codeToSend()
{
    return "1 (" + ex->codeToSend() + ") " + M1 ->codeToSend();
}
