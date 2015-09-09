#include "conditional_sequential_strategy.h"
#include "../../data/decision_pair.h"

#include <iostream>

using namespace std;

ConditionalSequentialStrategy::ConditionalSequentialStrategy(shared_ptr<CompoundModule> _M1, shared_ptr<CompoundModule> _M2, shared_ptr<BooleanExpression> _ex)
    : M1(_M1), M2(_M2), ex(_ex),
      output1(nullptr),
      output2(nullptr)
{}

shared_ptr<ComputationData> ConditionalSequentialStrategy::evaluate(shared_ptr<PSP> psp, shared_ptr<ComputationData> input)
{
    output1 = M1->execute(psp, input);
    output2 = M2->execute(psp, input);
    if (output1 == nullptr) return output2;
    if (output2 == nullptr) return output1;
    return (ex->evaluate(psp))
            ? output1
            : output2;
}
