#pragma once

#include "benchmark.h"

class Subsum : public Benchmark
{
    public:
        Subsum(std::vector<int> _values, int _subsum, int _n);

        int GetSubsum(){ return subsum; }
        int GetN(){ return n; }

        std::string showInstance();

    private:
        std::vector<int> values;
        int subsum, n;
};
