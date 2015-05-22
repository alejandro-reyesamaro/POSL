#pragma once

#include "parallel_computation_strategy.h"

class NotImplementedParallelStrategy : public ParallelComputationStrategy
{
    public:
        NotImplementedParallelStrategy();
        ComputationData * evaluate(Benchmark * bench, ComputationData * input);
};
