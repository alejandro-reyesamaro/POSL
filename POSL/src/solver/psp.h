#pragma once

#include "../benchmarks/benchmark.h"
#include "../data/solution.h"
#include "../computation/flag_computation.h"
#include "comunicator.h"

class PSP
{
    public:
        PSP(int _argc, char **_argv, shared_ptr<Benchmark> _bench);
        PSP(int _argc, char **_argv, shared_ptr<Benchmark> _bench, int _pID);



        int PSP::GetPID(){ return pID; }
        shared_ptr<Benchmark> PSP::GetBenchmark(){ return bench; }
        int PSP::GetIterations(){ return iterations; }
        int PSP::GetTime(){ return milisecs; }
        shared_ptr<Solution> PSP::GetBestSolutionSoFar(){ return best_found_solution; }
        shared_ptr<Solution> PSP::GetCurrentSolution(){ return bench->GetSolution(); }
        int PSP::CurrentCost(){ return bench->solutionCost(bench->GetSolution()); }
        int PSP::BestCostSoFar(){ return (best_found_solution == nullptr)? -1 : bench->solutionCost(best_found_solution); }


        void UpdateTime(int _milisecs);
        void CountIteration();
        void connectWith(int pID);
        void SendData(vector<int> data);
        void UpdateSolution(shared_ptr<Solution> solution);

        int ARGC;
        char **ARGV;

    private:

        shared_ptr<Benchmark> bench;
        int iterations;
        int milisecs;
        shared_ptr<Solution> best_found_solution;
        int pID;
        shared_ptr<Comunicator> comm;
        //! Proccesses IDs
        vector<int> connections;
};
