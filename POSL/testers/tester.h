#pragma once
#include <string>
#include "benchmarks/benchmark.h"

using namespace std;

class Tester
{
    public:
        Tester();
        virtual string test() = 0;
    protected:
        Benchmark * bench;
};
