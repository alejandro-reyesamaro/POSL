#pragma once

#include "create_solver_strategy.h"

class ForSquaringSquareCSS : public CreateSolverStrategy
{
    public:
        ForSquaringSquareCSS();
        CompoundModule *create();
};
