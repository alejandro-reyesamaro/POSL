#pragma once

#include "../benchmarks/benchmark.h"
#include "../data/solution.h"
#include "../computation/flag_computation.h"

class PSP
{
    public:
        PSP(int _argc, char **_argv, Benchmark * _bench);
        PSP(int _argc, char **_argv, Benchmark * _bench, FlagComputation * _computation);
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

        //void SetProccesA(int procID);
        //void SetProccesB(int procID);
        Computation computation();
        int ProcessA();
        int ProcessB();

    private:
        FlagParallelComputation * CastToParallelCOmputation();
        Benchmark * bench;
        int iterations;
        Solution * best_found_solution;
        int milisecs;
        FlagComputation * comp;
};
