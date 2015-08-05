#pragma once

#include "create_solver_strategy.h"

class ForGolfersCSS : public CreateSolverStrategy
{
    public:
        ForGolfersCSS();
        CompoundModule *create();
};
