#pragma once

#include "../data/solution.h"
#include "../benchmarks/benchmark.h"
#include "../modules/compound_module.h"
#include "factory_computation_strategy.h"

class ComputationStrategy
{
    public:
        ComputationStrategy(FactoryComputationStrategy * builder);
        Solution * execute(PSP * psp);

    private:
        CompoundModule * module;
};
