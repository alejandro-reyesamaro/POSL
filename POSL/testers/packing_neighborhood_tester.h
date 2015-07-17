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
        string test(Solution *sol, POSL_Iterator<vector<int>> * neighbors, vector<int> pack, string label);
};
