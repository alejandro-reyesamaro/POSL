#pragma once

#include "create_solver_strategy.h"

class ForGolombRulerCSS : public CreateSolverStrategy
{
    public:
        ForGolombRulerCSS();
        CompoundModule *create();
};
