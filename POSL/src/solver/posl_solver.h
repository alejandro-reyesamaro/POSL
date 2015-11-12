#pragma once

#include "psp.h"
#include "../computation/computation_strategy.h"
#include "../benchmarks/benchmark.h"
#include "../modules/compound_module.h"
#include "strategy/showing_result_strategy.h"

class POSL_Solver
{
    public:
        POSL_Solver(std::shared_ptr<Benchmark> _bench, std::shared_ptr<ComputationStrategy> _strategy);

        void solve(std::shared_ptr<PSP> psp);
        std::string show();

    private:
        std::shared_ptr<Solution> final_solution;
        std::shared_ptr<Solution> best_solution;
        int final_cost, best_cost, iterations, time;
        std::shared_ptr<ComputationStrategy> strategy;
        std::shared_ptr<Benchmark> bench;
        std::shared_ptr<ShowingResultStrategy> showing_strategy;
};
