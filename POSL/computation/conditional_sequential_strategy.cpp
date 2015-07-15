#include "conditional_sequential_strategy.h"
#include "data/decision_pair.h"

#include <iostream>

ConditionalSequentialStrategy::ConditionalSequentialStrategy(CompoundModule * _M1, CompoundModule * _M2, BooleanExpression *_ex)
    : M1(_M1), M2(_M2), ex(_ex)
{}

ComputationData * ConditionalSequentialStrategy::evaluate(PSP * psp, ComputationData * input)
{
    ComputationData * output = (ex->evaluate(psp))
            ? M1->execute(psp, input)
            : M2->execute(psp, input);
    return output;
}
