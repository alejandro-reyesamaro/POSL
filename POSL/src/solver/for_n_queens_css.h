#pragma once

#include "create_solver_strategy.h"
#include "../benchmarks/n_queens.h"

class ForNQueensCSS : public CreateSolverStrategy
{
    public:
        ForNQueensCSS(shared_ptr<NQueens> nq);
        vector<shared_ptr<POSL_Solver>> create();

    private:
        shared_ptr<POSL_Solver> single_solver;
        shared_ptr<POSL_Solver> receiver_solver;
        shared_ptr<POSL_Solver> sender_solver;
};
