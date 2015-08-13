#pragma once

#include "psp.h"
#include "../computation/computation_strategy.h"
#include "../benchmarks/benchmark.h"
#include "../modules/compound_module.h"
#include "../data/solution.h"

class POSL_Solver
{
    public:
        POSL_Solver(ComputationStrategy * _strategy);

        void solve(PSP * psp);
        string show(Benchmark * bench);
        string show();

    private:
        ComputationStrategy * strategy;

        bool Initialized(PSP * psp);
        string showSolution(string str_finalSol, string str_bestSol);

        Solution * final_solution, * best_solution;
        int final_cost, best_cost, iterations, time;
};
