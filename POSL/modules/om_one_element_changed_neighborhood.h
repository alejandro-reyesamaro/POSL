#pragma once

#include "operation_module.h"
#include "data/solution.h"
#include "benchmarks/benchmark.h"
#include "data/neighborhood.h"

class OM_OneElementChangedNeighborhood : public OperationModule
{
    public:
        OM_OneElementChangedNeighborhood();
        ComputationData * execute(Benchmark * bench, ComputationData * input);
};
