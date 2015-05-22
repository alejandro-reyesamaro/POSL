#pragma once

#include "benchmarks/benchmark.h"
#include "posl_iterator.h"

class VSearchState
{
    public:
        VSearchState();
        void updateState(Benchmark * _bench, POSL_Iterator<vector<int>> * _it, int _current_cost, int _best_cost, int _found_cost);
        virtual bool keepSearching() = 0;

    protected:
        Benchmark * bench;
        POSL_Iterator<vector<int>> * it;
        int current_cost, best_cost, found_cost;
};
