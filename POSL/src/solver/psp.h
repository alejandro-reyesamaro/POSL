#pragma once

#include "../benchmarks/benchmark.h"
#include "../data/solution.h"
#include "../computation/flag_computation.h"
#include "comunicator.h"

class PSP
{
    public:
        PSP(int _argc, char **_argv, Benchmark * _bench);
        PSP(int _argc, char **_argv, Benchmark * _bench, int _pID);
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
        int GetPID();
        void connectWith(int pID);
        void SendData(ComputationData *data);

        int ARGC;
        char **ARGV;

    private:

        Benchmark * bench;
        int iterations;
        int milisecs;
        Solution * best_found_solution;
        int pID;
        Comunicator * comm;
        //! Proccesses IDs
        vector<int> connections;
};
