#include "min_parallel_strategy.h"

#include <iostream>
#include <thread>

#define TAG 123

MinParallelStrategy::MinParallelStrategy(shared_ptr<CompoundModule> _M1, shared_ptr<CompoundModule> _M2)
    : M1(_M1), M2(_M2),
      result1(nullptr),
      result2(nullptr),
      mincrit(make_shared<MinCritComparison>())
{}

shared_ptr<ComputationData> MinParallelStrategy::evaluate(shared_ptr<PSP> psp, shared_ptr<ComputationData> input)
{
    thread workerThread(&Executer::execute, &M2, psp, input);
    M1.execute(psp, input);
    result1 = M1.GetOutput();
    workerThread.join();
    result2 = M2.GetOutput();

    if (result1 == nullptr) return result2;
    if (result2 == nullptr) return result1;
    return mincrit->getMin(result1, result2, psp);
}
