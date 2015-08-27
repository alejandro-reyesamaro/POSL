#pragma once

#include "create_solver_strategy.h"

class ForSquaringSquareCSS : public CreateSolverStrategy
{
    public:
        ForSquaringSquareCSS();
        vector<POSL_Solver *> create();
};
