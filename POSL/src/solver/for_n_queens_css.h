#pragma once

#include "create_solver_strategy.h"
#include "../benchmarks/n_queens.h"

class ForNQueensCSS : public CreateSolverStrategy
{
    public:
        ForNQueensCSS(NQueens * nq);
        vector<POSL_Solver *> create();

    private:
        POSL_Solver * single_solver;
        POSL_Solver * receiver_solver;
        POSL_Solver * sender_solver;
};
