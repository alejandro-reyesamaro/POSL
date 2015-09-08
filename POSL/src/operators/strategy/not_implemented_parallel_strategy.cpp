#include "not_implemented_parallel_strategy.h"

NotImplementedParallelStrategy::NotImplementedParallelStrategy()
{
}

shared_ptr<ComputationData> NotImplementedParallelStrategy::evaluate(shared_ptr<PSP> psp, shared_ptr<ComputationData> input)
{
    throw "Parallel strategy not supported";
}
