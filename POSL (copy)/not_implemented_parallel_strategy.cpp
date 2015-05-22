#include "not_implemented_parallel_strategy.h"

NotImplementedParallelStrategy::NotImplementedParallelStrategy()
{
}

ComputationData * NotImplementedParallelStrategy::evaluate(Benchmark * bench, ComputationData * input)
{
    throw "Parallel strategy not supported";
}
