#pragma once

#include "benchmarks/benchmark.h"

#include <iostream>
#include <string>

using namespace std;

class Tester
{
    public:
        Tester();
        virtual string test() = 0;
    protected:
        Benchmark * bench;
};
