#pragma once

#include "data/computation_data.h"
#include "benchmarks/benchmark.h"
#include "modules/compound_module.h"

class ComputationStrategy
{
    public:
        virtual ComputationData * evaluate(Benchmark * bench, ComputationData * input) = 0;
};
