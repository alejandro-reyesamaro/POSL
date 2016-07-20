#pragma once

#include "psp.h"
#include "../computation/computation_strategy.h"
#include "../benchmarks/benchmark.h"
#include "../modules/compound_module.h"
#include "strategy/showing_result_strategy.h"
#include "../connections/connectable.h"

class POSL_Solver : public Connectable
{
    public:
        POSL_Solver(std::string name,
                    std::shared_ptr<Benchmark> _bench,
                    std::shared_ptr<ComputationStrategy> _strategy,
                    shared_ptr<SearchProcessParamsStruct> _psp_params);

        void solve(std::shared_ptr<PSP> psp);
        std::string show(std::shared_ptr<PSP> psp);
        std::string GetSolverName() { return solver_name; }
        void expandSolverName(std::string sufix);
        shared_ptr<SearchProcessParamsStruct> GetPspParams(){ return psp_params; }

        bool isOpen();

        std::vector<ConnectorInfo> Jacks();
        std::vector<ConnectorInfo> Outlets();
        void connect(ConnectorInfo connector, int procID);

    private:
        std::string solver_name;
        std::shared_ptr<Solution> final_solution;
        std::shared_ptr<Solution> best_solution;
        int final_cost, best_cost, iterations, time;
        std::shared_ptr<ComputationStrategy> strategy;
        std::shared_ptr<Benchmark> bench;
        std::shared_ptr<ShowingResultStrategy> showing_strategy;
        shared_ptr<SearchProcessParamsStruct> psp_params;
};
