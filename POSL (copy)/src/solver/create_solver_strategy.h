#pragma once

#include "posl_solver.h"

class CreateSolverStrategy
{
    public:
        virtual vector<POSL_Solver *> create() = 0;
};
