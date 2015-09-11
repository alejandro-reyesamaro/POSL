#pragma once

#include "psp.h"
#include "../computation/computation_strategy.h"
#include "../benchmarks/benchmark.h"
#include "../modules/compound_module.h"
#include "../data/solution.h"

class POSL_Solver
{
    public:
        POSL_Solver(std::shared_ptr<ComputationStrategy> _strategy);

        void solve(std::shared_ptr<PSP> psp);
        std::string show(std::shared_ptr<Benchmark> bench);
        std::string show();

    private:
        std::string showSolution(std::string str_finalSol, std::string str_bestSol);

        std::shared_ptr<Solution> final_solution;
        std::shared_ptr<Solution> best_solution;
        int final_cost, best_cost, iterations, time;
        std::shared_ptr<ComputationStrategy> strategy;
};
