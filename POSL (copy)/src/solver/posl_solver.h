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

        string showSolution(string str_finalSol, string str_bestSol);

        ComputationStrategy * strategy;
        Solution * final_solution, * best_solution;
        int final_cost, best_cost, iterations, time;
};
