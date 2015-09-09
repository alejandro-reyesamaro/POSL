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



        int GetPID(){ return pID; }
        std::shared_ptr<Benchmark> GetBenchmark(){ return bench; }
        int GetIterations(){ return iterations; }
        int GetTime(){ return milisecs; }
        std::shared_ptr<Solution> GetBestSolutionSoFar(){ return best_found_solution; }
        std::shared_ptr<Solution> GetCurrentSolution(){ return bench->GetSolution(); }
        int CurrentCost(){ return bench->solutionCost(bench->GetSolution()); }
        int BestCostSoFar(){ return (best_found_solution == nullptr)? -1 : bench->solutionCost(best_found_solution); }


        void UpdateTime(int _milisecs);
        void CountIteration();
        void connectWith(int pID);
        void SendData(std::vector<int> data);
        void UpdateSolution(std::shared_ptr<Solution> solution);

        int ARGC;
        char **ARGV;

    private:

        std::shared_ptr<Benchmark> bench;
        int iterations;
        int milisecs;
        std::shared_ptr<Solution> best_found_solution;
        int pID;
        std::shared_ptr<Comunicator> comm;
        //! Proccesses IDs
        std::vector<int> connections;
};
