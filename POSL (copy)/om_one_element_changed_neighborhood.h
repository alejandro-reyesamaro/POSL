#pragma once

#include "operation_module.h"
#include "solution.h"
#include "benchmark.h"
#include "neighborhood.h"

class OM_OneElementChangedNeighborhood : public OperationModule
{
    public:
        OM_OneElementChangedNeighborhood();
        ComputationData * execute(Benchmark * bench, ComputationData * input);
};
