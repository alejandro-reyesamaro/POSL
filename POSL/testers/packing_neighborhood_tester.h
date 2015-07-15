#pragma once

#include <string>
#include "data/dStrategy/posl_iterator.h"
#include "benchmarks/benchmark.h"
#include "data/solution.h"

using namespace std;

class PackingNeighborhoodTester
{
    public:
        PackingNeighborhoodTester();
        string test(Benchmark *bench, Solution *sol, POSL_Iterator<vector<int>> * neighbors, int * pack, string label);
};
