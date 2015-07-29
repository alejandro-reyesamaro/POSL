#pragma once

#include "../benchmarks/benchmark.h"
#include "../data/solution.h"

class PSP
{
    public:
        PSP(int _argc, char **_argv, Benchmark * _bench);
        void UpdateSolution(Solution * solution);

        Benchmark * GetBenchmark();
        int GetIterations();
        int GetTime();
        Solution * GetBestSolutionSoFar();
        Solution * GetCurrentSolution();
        int CurrentCost();
        int BestCostSoFar();
        void UpdateTime(int _milisecs);
        void CountIteration();

        int ARGC;
        char **ARGV;

    private:        
        Benchmark * bench;
        int iterations;
        Solution * best_found_solution;
        int milisecs;
};
