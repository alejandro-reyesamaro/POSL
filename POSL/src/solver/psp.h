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

        //! Properties
        int GetPID(){ return pID; }
        std::shared_ptr<Benchmark> GetBenchmark(){ return bench; }
        int GetIterations(){ return iterations; }
        int GetTime(){ return milisecs; }
        std::shared_ptr<Solution> GetBestSolutionSoFar(){ return std::make_shared<Solution>(bench->Domains(), best_found_configuration); }
        inline std::shared_ptr<Solution> GetCurrentSolution(){ return bench->GetSolution(); }        
        int CurrentCost() { return bench->currentCost(); }
        int BestCostSoFar() { return best_found_cost; }

        //! State functions
        void Start(std::vector<int> config);
        void UpdateTime(int _milisecs);
        void CountIteration();
        //void connectWith(int pID);
        void UpdateSolution(std::vector<int> config);

        void SendData(std::vector<int> data, std::vector<int> destinies);

        int ARGC;
        char **ARGV;

    private:
        std::shared_ptr<Benchmark> bench;
        int iterations;
        int milisecs;
        std::vector<int> best_found_configuration;
        int best_found_cost;
        int pID;
        std::shared_ptr<Comunicator> comm;
        //! Proccesses IDs
        //std::vector<int> connections;
};
