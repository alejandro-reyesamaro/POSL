#pragma once

#include "psp.h"
#include "create_solver_strategy.h"
#include "../benchmarks/benchmark.h"
#include "../modules/compound_module.h"
#include "../data/solution.h"

class POSL_Solver
{
    public:
        /*
        POSL_Solver(int _argc, char **_argv,
                    Benchmark * _bench,
                    CreateSolverStrategy * create_strategy,
                    int procA, int procB, int procID);
        POSL_Solver(int _argc, char **_argv,
                    Benchmark * _bench,
                    CreateSolverStrategy * create_strategy);
        */
        POSL_Solver(CreateSolverStrategy * create_strategy);

        void solve(PSP * psp);
        string show(Benchmark * bench);
        string show();

    private:
        bool Initialized(PSP * psp);
        string showSolution(string str_finalSol, string str_bestSol);

        Solution * final_solution, * best_solution;
        int final_cost, best_cost, iterations, time;
        CompoundModule * module;
};
