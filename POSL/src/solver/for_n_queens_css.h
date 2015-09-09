#pragma once

#include "create_solver_strategy.h"
#include "../benchmarks/n_queens.h"

class ForNQueensCSS : public CreateSolverStrategy
{
    public:
        ForNQueensCSS(std::shared_ptr<NQueens> nq);
        std::vector<std::shared_ptr<POSL_Solver>> create();

    private:
        std::shared_ptr<POSL_Solver> single_solver;
        std::shared_ptr<POSL_Solver> receiver_solver;
        std::shared_ptr<POSL_Solver> sender_solver;
};
