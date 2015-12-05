#pragma once

#include "../benchmarks/benchmark.h"
#include "../data/solution.h"
#include "comunicator.h"

class PSP
{
    public:
        PSP(std::shared_ptr<Benchmark> _bench);
        PSP(std::shared_ptr<Benchmark> _bench, int _pID);

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
        void UpdateSolution(std::vector<int> config);

        //int ARGC;
        //char **ARGV;

    private:
        std::shared_ptr<Benchmark> bench;
        int iterations;
        int milisecs;
        std::vector<int> best_found_configuration;
        int best_found_cost;
        int pID;
};
