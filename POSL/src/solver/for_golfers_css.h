#pragma once

#include "create_solver_strategy.h"
#include "../benchmarks/golfers.h"

class ForGolfersCSS : public CreateSolverStrategy
{
    public:
        ForGolfersCSS(Golfers * golfers);
        vector<POSL_Solver *> create();
};
