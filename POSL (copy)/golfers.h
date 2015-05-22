#pragma once

#include "benchmark.h"

using namespace std;

class Golfers : public Benchmark
{
    public:
        Golfers(int g, int p, int w);
        int solutionCost(Solution * sol);

    private:
        int groups, players, weeks;
};
