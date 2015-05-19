#pragma once

#include "operation_module.h"
#include "solution.h"
#include "benchmark.h"

class OM_FlorianRandomConfGeneration : public OperationModule<shared_ptr<Benchmark>, vector<int>>
{
    public:
        OM_FlorianRandomConfGeneration();
        vector<int> execute(shared_ptr<Benchmark> input);
};
