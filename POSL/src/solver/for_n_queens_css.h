#pragma once

#include "create_solver_strategy.h"

class ForNQueensCSS : public CreateSolverStrategy
{
    public:
        ForNQueensCSS();
        vector<POSL_Solver *> create();
};
