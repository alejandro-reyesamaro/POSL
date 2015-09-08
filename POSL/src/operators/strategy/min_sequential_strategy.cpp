#include "min_sequential_strategy.h"

#include <iostream>
using namespace std;

MinSequentialStrategy::MinSequentialStrategy(shared_ptr<CompoundModule> _M1, shared_ptr<CompoundModule> _M2)
    : M1(_M1), M2(_M2),
      result1(nullptr),
      result2(nullptr),
      mincrit(new MinCritComparison())
{}

shared_ptr<ComputationData> MinSequentialStrategy::evaluate(shared_ptr<PSP> psp, shared_ptr<ComputationData> input)
{
    result1 = M1->execute(psp, input);
    result2 = M2->execute(psp, input);

    if (result1 == nullptr) return result2;
    if (result2 == nullptr) return result1;

    return mincrit->getMin(result1, result2, psp);
}
