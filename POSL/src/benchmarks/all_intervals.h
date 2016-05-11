#pragma once

#include "benchmark.h"
#include "cost_strategy/all_interval_relative_cost_strategy.h"

class AllIntervals : public Benchmark
{
    public:
        AllIntervals(int _n);

        int N(){ return n; }
        std::string showInstance();
        std::vector<int> Reset();

    private:
        std::shared_ptr<AllIntervalRelativeCostStrategy> cast_my_relative_strategy();

        int n;
};
