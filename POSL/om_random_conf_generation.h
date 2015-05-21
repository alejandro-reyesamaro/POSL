#pragma once

#include "operation_module.h"
#include "solution.h"
#include "benchmark.h"
#include "seed.h"

class OM_RandomConfGeneration : public OperationModule
{
    public:
        OM_RandomConfGeneration();
        ComputationData * execute(Benchmark * bench, ComputationData * input);

    private:
        // casting
        Solution * CastForSolution(ComputationData * output);
        Seed * CastForSeed(ComputationData * input);
};
