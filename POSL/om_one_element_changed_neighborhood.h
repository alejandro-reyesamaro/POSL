#pragma once

#include "operation_module.h"
#include "solution.h"
#include "benchmark.h"
#include "neighborhood.h"

class OM_OneElementChangedNeighborhood : public OperationModule<shared_ptr<Benchmark>, shared_ptr<Neighborhood>>
{
    public:
        OM_OneElementChangedNeighborhood();
        shared_ptr<Neighborhood> execute(shared_ptr<Benchmark> input);
};
