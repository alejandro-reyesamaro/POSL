#pragma once

#include "psp.h"
#include "create_solver_strategy.h"
#include "../benchmarks/benchmark.h"
#include "../modules/compound_module.h"
#include "../data/solution.h"

class POSL_Solver
{
    public:
        POSL_Solver(int _argc, char **_argv,
                    Benchmark * _bench,
                    CreateSolverStrategy * create_strategy,
                    int procA, int procB, int procID);
        POSL_Solver(int _argc, char **_argv,
                    Benchmark * _bench,
                    CreateSolverStrategy * create_strategy);
        POSL_Solver(PSP * _psp, CreateSolverStrategy * create_strategy);
        bool Initialized();
        void solve();
        string show();

    private:
        Solution * final_solution, * best_solution;
        int final_cost, best_cost;
        PSP * psp;
        CompoundModule * module;
};
