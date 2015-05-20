#pragma once

#include "benchmark.h"

using namespace std;

class Golfers : public Benchmark
{
    public:
        Golfers(int g, int p, int w);
        int solutionCost(shared_ptr<Solution> sol);

    private:
        int groups, players, weeks;
};
