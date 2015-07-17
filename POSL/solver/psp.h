#pragma once

#include "benchmarks/benchmark.h"
#include "data/solution.h"

class PSP
{
    public:
        PSP(int _argc, char **_argv, Benchmark * _bench);
        void UpdateBestSolution(Solution * sol);
        void UpdateSolution(Solution * sol);

        Benchmark * GetBenchmark();
        int GetIterations();
        Solution * GetBestSolutionSoFar();
        Solution * GetCurrentSolution();
        int CurrentCost();
        int BestCostSoFar();

        int ARGC;
        char **ARGV;

    private:        
        Benchmark * bench;
        int iterations;
        Solution * best_found_solution;
};
