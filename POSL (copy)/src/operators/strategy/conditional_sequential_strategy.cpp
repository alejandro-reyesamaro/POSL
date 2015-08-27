#include "conditional_sequential_strategy.h"
#include "../../data/decision_pair.h"

#include <iostream>

ConditionalSequentialStrategy::ConditionalSequentialStrategy(CompoundModule * _M1, CompoundModule * _M2, BooleanExpression *_ex)
    : M1(_M1), M2(_M2), ex(_ex)
{}

ComputationData * ConditionalSequentialStrategy::evaluate(PSP * psp, ComputationData * input)
{
    ComputationData * output1 = M1->execute(psp, input);
    ComputationData * output2 = M2->execute(psp, input);
    if (output1 == NULL) return output2;
    if (output2 == NULL) return output1;
    ComputationData * output = (ex->evaluate(psp))
            ? output1
            : output2;
    return output;
}
