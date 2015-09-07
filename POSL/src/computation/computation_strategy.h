#pragma once

#include "../data/solution.h"
#include "../benchmarks/benchmark.h"
#include "../modules/compound_module.h"
#include "factory_computation_strategy.h"

class ComputationStrategy
{
    public:
        ComputationStrategy(shared_ptr<FactoryComputationStrategy> builder);
        shared_ptr<Solution> execute(shared_ptr<PSP> psp);

    private:
        shared_ptr<CompoundModule> module;
};
