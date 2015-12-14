#pragma once

#include "benchmark.h"

class CostasArray : public Benchmark
{
    public:
        CostasArray(int _n);

        int N(){ return n; }

        std::string showInstance();

    private:
        int n;
};
