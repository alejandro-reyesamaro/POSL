#pragma once

#include "operation_module.h"
#include "solution.h"
#include "benchmark.h"
#include "seed.h"

class OM_FlorianRandomConfGeneration : public OperationModule
{
    public:
        OM_FlorianRandomConfGeneration();
        ComputationData * execute(Benchmark * bench, ComputationData * input);
};
