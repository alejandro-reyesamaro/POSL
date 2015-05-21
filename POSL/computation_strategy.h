#pragma once

#include "computation_data.h"
#include "benchmark.h"
#include "compound_module.h"

class ComputationStrategy
{
    public:
        virtual ComputationData * evaluate(Benchmark * bench, ComputationData * input) = 0;
};
