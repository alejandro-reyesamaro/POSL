#include "conditional_operator.h"
#include "../computation/not_implemented_parallel_strategy.h"
#include "../computation/conditional_sequential_strategy.h"

ConditionalOperator::ConditionalOperator(CompoundModule * _M1, CompoundModule * _M2, BooleanExpression * _ex)
    : BinaryOperator(_M1, _M2, new ConditionalSequentialStrategy(_M1, _M2, _ex), new NotImplementedParallelStrategy()),
      ex(_ex)
{}

string ConditionalOperator::codeToSend()
{
    return "2 (" + ex->codeToSend() + ") " + M1 ->codeToSend() + " " + M2->codeToSend();
}
