#pragma once

#include "../benchmarks/benchmark.h"
#include "../data/solution.h"
#include "comunicator.h"
#include "../tools/posl_log.h"

class PSP
{
    public:
        PSP(std::shared_ptr<Benchmark> _bench);
        PSP(std::shared_ptr<Benchmark> _bench, int _pID);
        PSP(std::shared_ptr<Benchmark> _bench, int _pID, std::string _logs_path);

        //! Properties
        int GetPID() { return pID; }
        std::shared_ptr<Benchmark> GetBenchmark() { return bench; }
        int GetIterations() { return iterations; }
        int GetTime() { return milisecs; }
        std::shared_ptr<Solution> GetBestSolutionSoFar() { return std::make_shared<Solution>(bench->Domains(), best_found_configuration); }
        inline std::shared_ptr<Solution> GetCurrentSolution() { return bench->GetSolution(); }
        int CurrentCost() { return bench->currentCost(); }
        int BestCostSoFar() { return best_found_cost; }
        bool FoundThanksOuterInformation() { return found_thanks_outer_information; }
        void SetTimeOut(int milliseconds) { time_out = milliseconds; }
        int GetTimeOut() { return time_out; }
        std::shared_ptr<Seed> GetSeed() { return the_seed; }

        //! State functions
        void Start(std::vector<int> config);
        void UpdateTime(int _milisecs);
        void CountIteration();
        void UpdateSolution(std::vector<int> config);
        void SearchingWithOuterInformation_ON() { outer_information = true; }
        void SearchingWithOuterInformation_OFF() { outer_information = false; }

        //void log(std::string text);

    private:
        std::shared_ptr<Benchmark> bench;
        int iterations;
        int milisecs;
        std::vector<int> best_found_configuration;
        int best_found_cost;
        int pID;
        bool outer_information;
        bool found_thanks_outer_information;
        int time_out;
        POSL_Log plog;
        std::string logs_path;
        std::shared_ptr<Seed> the_seed;
};
