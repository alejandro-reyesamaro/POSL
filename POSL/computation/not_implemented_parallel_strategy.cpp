#include "not_implemented_parallel_strategy.h"

NotImplementedParallelStrategy::NotImplementedParallelStrategy()
{
}

ComputationData * NotImplementedParallelStrategy::evaluate(PSP * psp, ComputationData * input)
{
    throw "Parallel strategy not supported";
}
