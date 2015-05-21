#pragma once

#include "sequential_computation_strategy.h"

class SequentialExecutionSequentialStrategy : public SequentialComputationStrategy
{
    public:
        SequentialExecutionSequentialStrategy(CompoundModule * _M1, CompoundModule * _M2);
        ComputationData * evaluate(Benchmark * bench, ComputationData * input);

    private:
        CompoundModule * M1;
        CompoundModule * M2;
};
