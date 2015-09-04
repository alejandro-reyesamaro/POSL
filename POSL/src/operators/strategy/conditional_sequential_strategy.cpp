#include "conditional_sequential_strategy.h"
#include "../../data/decision_pair.h"

#include <iostream>

ConditionalSequentialStrategy::ConditionalSequentialStrategy(CompoundModule * _M1, CompoundModule * _M2, BooleanExpression *_ex)
    : M1(_M1), M2(_M2), ex(_ex),
      output1(nullptr),
      output2(nullptr)
{}

ComputationData * ConditionalSequentialStrategy::evaluate(PSP * psp, ComputationData * input)
{
    output1 = M1->execute(psp, input);
    output2 = M2->execute(psp, input);
    if (output1 == nullptr) return output2;
    if (output2 == nullptr) return output1;
    ComputationData * output = (ex->evaluate(psp))
            ? output1
            : output2;
    return output;
}
