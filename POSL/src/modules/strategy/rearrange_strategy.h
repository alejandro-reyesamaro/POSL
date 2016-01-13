#pragma once

#include "../../data/solution.h"
#include "../../benchmarks/benchmark.h"

class RearrangeStrategy
{
    public:
        virtual std::shared_ptr<Solution> rearrangement(std::vector<int> current_configuration, std::shared_ptr<Benchmark> benchmark) = 0;
};
