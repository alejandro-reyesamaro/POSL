#pragma once

#include "../benchmarks/benchmark.h"
#include "../data/solution.h"
#include "../computation/flag_computation.h"
#include "comunicator.h"

class PSP
{
    public:
        PSP(int _argc, char **_argv, std::shared_ptr<Benchmark> _bench);
        PSP(int _argc, char **_argv, std::shared_ptr<Benchmark> _bench, int _pID);

        inline int GetPID(){ return pID; }
        inline std::shared_ptr<Benchmark> GetBenchmark(){ return bench; }
        inline int GetIterations(){ return iterations; }
        inline int GetTime(){ return milisecs; }
        std::shared_ptr<Solution> GetBestSolutionSoFar();
        inline std::shared_ptr<Solution> GetCurrentSolution(){ return bench->GetSolution(); }
        inline int CurrentCost(){ return bench->solutionCost(bench->GetSolution()); }
        int BestCostSoFar();


        void UpdateTime(int _milisecs);
        void CountIteration();
        void connectWith(int pID);
        void SendData(std::vector<int> data);        
        void UpdateSolution(std::vector<int> config);
        void Start(std::vector<int> config);

        int ARGC;
        char **ARGV;

    private:
        std::shared_ptr<Benchmark> bench;
        int iterations;
        int milisecs;
        std::vector<int> best_found_configuration;
        int pID;
        std::shared_ptr<Comunicator> comm;
        //! Proccesses IDs
        std::vector<int> connections;
};
