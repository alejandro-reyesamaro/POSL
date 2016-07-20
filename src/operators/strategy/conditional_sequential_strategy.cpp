#include "conditional_sequential_strategy.h"
#include "../../data/decision_pair.h"

#include <iostream>

using namespace std;

ConditionalSequentialStrategy::ConditionalSequentialStrategy(shared_ptr<CompoundModule> _M1, shared_ptr<CompoundModule> _M2, shared_ptr<BooleanExpression> _ex)
    : M1(_M1), M2(_M2), ex(_ex),
      output(nullptr)
{}

shared_ptr<ComputationData> ConditionalSequentialStrategy::evaluate(shared_ptr<PSP> psp, shared_ptr<ComputationData> input)
{
    if(ex->evaluate(psp))
        output = M1->execute(psp, input);
    else
        output = M2->execute(psp, input);
    return output;
}
