#include "cyclic_operator.h"
#include "../computation/cyclic_sequential_strategy.h"

CyclicOperator::CyclicOperator(CompoundModule * _M1, BooleanExpression * _ex)
    : UnaryOperator(_M1, new CyclicSequentialStrategy(_M1, _ex)),
      ex(_ex)
{}

string CyclicOperator::codeToSend()
{
    return "1 (" + ex->codeToSend() + ") " + M1 ->codeToSend();
}
