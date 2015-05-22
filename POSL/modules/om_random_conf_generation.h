#pragma once

#include "operation_module.h"
#include "data/solution.h"
#include "benchmarks/benchmark.h"
#include "data/seed.h"

class OM_RandomConfGeneration : public OperationModule
{
    public:
        OM_RandomConfGeneration();
        ComputationData * execute(Benchmark * bench, ComputationData * input);
};
