#pragma once

#include "create_solver_strategy.h"
#include "../benchmarks/squaring_square.h"

class ForSquaringSquareCSS : public CreateSolverStrategy
{
    public:
        ForSquaringSquareCSS(SquaringSquare * ssq);
        vector<POSL_Solver *> create();

    private:
        POSL_Solver * single_solver;
        POSL_Solver * receiver_solver;
        POSL_Solver * sender_solver;
};
