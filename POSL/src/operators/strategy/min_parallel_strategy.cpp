#include "min_parallel_strategy.h"
#include "min_crit_comparison.h"

#include <iostream>
#include <thread>

#define TAG 123

MinParallelStrategy::MinParallelStrategy(CompoundModule *_M1, CompoundModule *_M2)
    : M1(_M1), M2(_M2)
{}

ComputationData * MinParallelStrategy::evaluate(PSP *psp, ComputationData * input)
{
    thread workerThread(&Executer::execute, &M2, psp, input);
    M1.execute(psp, input);
    ComputationData * r1 = M1.GetOutput();
    workerThread.join();
    ComputationData * r2 = M2.GetOutput();

    if (r1 == NULL) return r2;
    if (r2 == NULL) return r1;

    MinCritComparison * mincrit = new MinCritComparison();
    return mincrit->getMin(r1, r2, psp);
}
