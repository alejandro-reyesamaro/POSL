#pragma once

#include "../benchmarks/benchmark.h"
#include "../data/solution.h"
#include "comunicator.h"
#include "../tools/posl_log.h"
#include "../tools/tabu_list.h"

class PSP
{
    public:
        PSP(std::shared_ptr<Benchmark> _bench);
        PSP(std::shared_ptr<Benchmark> _bench, int _pID);
        PSP(std::shared_ptr<Benchmark> _bench, int _pID, std::string _logs_path);

         //!   | Properties |
        int GetPID() { return pID; }
        int GetIterations() { return iterations; }
        int GetTime() { return milisecs; }
        void SetTimeOut(int milliseconds) { time_out = milliseconds; }
        int GetTimeOut() { return time_out; }
        bool FoundThanksOuterInformation() { return found_thanks_outer_information; }
        std::shared_ptr<Randomizer> GetRandomizer() { return rand; }
        //! Benchmark
        std::shared_ptr<Benchmark> GetBenchmark() { return bench; }
        std::shared_ptr<Solution> GetBestSolutionSoFar()
        {
            return std::make_shared<Solution>(bench->Variable_Domain(), best_found_configuration);
        }
        inline std::shared_ptr<Solution> GetCurrentSolution() { return bench->GetSolution(); }
        int CurrentCost() { return bench->currentCost(); }
        int BestCostSoFar() { return best_found_cost; }

         //!   | State functions |
        void Start(vector<int> & config);
        void UpdateTime(int _milisecs);
        void CountIteration();
        void StartSearch();
        int Restarts(){ return restarts; }
        void UpdateSolution(vector<int> & config);
        void SearchingWithOuterInformation_ON() { outer_information = true; }
        void SearchingWithOuterInformation_OFF() { outer_information = false; }

        //void log(std::string text);
        void addTabuSolution(vector<int> & configuration);
        bool isGlobalTabu(vector<int> & configuration, float eps);
        bool isGlobalTabu(vector<int> & configuration);

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
        int restarts;
        std::shared_ptr<Randomizer> rand;
        std::shared_ptr<TabuList> tabu_list;
};
