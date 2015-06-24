#pragma once

#include "benchmarks/benchmark.h"
#include "data/solution.h"

class PSP
{
    public:
        PSP(Benchmark * _bench);
        void UpdateBestSolution(Solution * sol);
        void UpdateSolution(Solution * sol);

        Benchmark * GetBenchmark();
        int GetIterations();
        Solution * GetBestSolutionSoFar();
        Solution * GetCurrentSolution();
        int CurrentCost();
        int BestCostSoFar();

    private:
        Benchmark * bench;
        int iterations;
        Solution * best_found_solution;
};
