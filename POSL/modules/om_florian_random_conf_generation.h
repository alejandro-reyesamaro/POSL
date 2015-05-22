#pragma once

#include "operation_module.h"
#include "data/solution.h"
#include "benchmarks/benchmark.h"
#include "data/seed.h"

class OM_FlorianRandomConfGeneration : public OperationModule
{
    public:
        OM_FlorianRandomConfGeneration();
        ComputationData * execute(Benchmark * bench, ComputationData * input);
};
