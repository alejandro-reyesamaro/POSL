#pragma once

#include "create_solver_strategy.h"
#include "../benchmarks/squaring_square.h"

class ForSquaringSquareCSS : public CreateSolverStrategy
{
    public:
        ForSquaringSquareCSS(shared_ptr<SquaringSquare> ssq);
        vector<shared_ptr<POSL_Solver>> create();

    private:
        shared_ptr<POSL_Solver> single_solver;
        shared_ptr<POSL_Solver> receiver_solver;
        shared_ptr<POSL_Solver> sender_solver;
};
