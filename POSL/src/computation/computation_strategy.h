#pragma once

#include "../data/solution.h"
#include "../benchmarks/benchmark.h"
#include "../modules/compound_module.h"
#include "factory_computation_strategy.h"

class ComputationStrategy
{
    public:
        ComputationStrategy(std::shared_ptr<FactoryComputationStrategy> builder);
        std::shared_ptr<Solution> execute(std::shared_ptr<PSP> psp);

    private:
        std::shared_ptr<CompoundModule> module;
};
