#pragma once

#include "operation_module.h"
#include "solution.h"
#include "benchmark.h"

class OM_RandomConfGeneration : public OperationModule<shared_ptr<Benchmark>, vector<int>>
{
    public:
        OM_RandomConfGeneration();
        vector<int> execute(shared_ptr<Benchmark> input);
};
