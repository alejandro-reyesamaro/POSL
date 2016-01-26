#pragma once

#include "benchmark.h"
#include "cost_strategy/costas_array_relative_cost_strategy.h"

class CostasArray : public Benchmark
{
    public:
        CostasArray(int _n);

        int N(){ return n; }

        std::string showInstance();

        std::vector<int> Reset(std::vector<int> current_configuration);

    private:
        std::shared_ptr<CostasArrayRelativeCostStrategy> cast_my_relative_strategy();

        int n;
};
