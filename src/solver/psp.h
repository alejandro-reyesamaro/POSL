#pragma once

#include "../benchmarks/benchmark.h"
#include "../data/solution.h"
#include "comunicator.h"
#include "../tools/posl_log.h"
#include "tabu_object.h"
#include "search_process_params_struct.h"

class PSP
{
    public:
        PSP(std::shared_ptr<Benchmark> _bench);
        PSP(std::shared_ptr<Benchmark> _bench, int _pID);
        //PSP(std::shared_ptr<Benchmark> _bench, int _pID, std::string _logs_path);
        PSP(std::shared_ptr<Benchmark> _bench, std::shared_ptr<SearchProcessParamsStruct> _params);


         //!   | Properties |
        int GetPID() { return params->pID; }
        int GetIterations() { return iterations; }
        int GetTime() { return milisecs; }
        //void SetTimeOut(int milliseconds) { time_out = milliseconds; }
        int GetTimeOut() { return params->max_time_miliseconds; }
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

        //! Tabu
        std::shared_ptr<TabuObject> GetTabuObject() { return tabu_object; }

         //!   | State functions |
        void Start(vector<int> & config);
        void UpdateTime(int _milisecs);
        void CountIteration();
        void StartSearch();
        int Restarts(){ return restarts; }
        void UpdateSolution(vector<int> & config);
        void SearchingWithOuterInformation_ON() { outer_information = true; report_accepted_package(); }
        void SearchingWithOuterInformation_OFF() { outer_information = false; }

        //void log(std::string text);

        void clear_information();

        //! Statistic


        void report_received_package(int milliseconds);
        void report_accepted_package();
        void report_sent_package(int milliseconds);

        int get_sent_packages(){ return data_counters[0]; }
        int get_average_time_of_sent_packages(){ return data_times_averages[0]; }
        int get_received_packages(){ return data_counters[1]; }
        int get_average_time_of_received_packages(){ return data_times_averages[1]; }
        int get_accepted_packages(){ return data_counters[2]; }
        int get_average_time_of_accepted_packages(){ return data_times_averages[2]; }

    private:
        void store_information_exchange_statistic(int milliseconds, int & packages_count, float &time);

        std::shared_ptr<Benchmark> bench;
        int iterations;
        int milisecs;

        std::vector<int> best_found_configuration;
        int best_found_cost;
        //int pID;
        bool outer_information;
        bool found_thanks_outer_information;

        //int time_out;
        //POSL_Log plog;
        //std::string logs_path;
        int restarts;
        std::shared_ptr<Randomizer> rand;
        std::shared_ptr<TabuObject> tabu_object;        
        std::shared_ptr<SearchProcessParamsStruct> params;

        //! [ sent, received, accepted ]
        std::vector<int> data_counters;
        std::vector<float> data_times_averages;

        //! AUX vars
        float sum;
};
