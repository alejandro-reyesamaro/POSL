#pragma once

#include "parallelc_computation_strategy.h"

class NotImplementedParallelStrategy : public ParallelComputationStrategy
{
    public:
        NotImplementedParallelStrategy();
        ComputationData * evaluate(Benchmark * bench, ComputationData * input);
};
