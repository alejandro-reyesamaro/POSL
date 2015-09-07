#pragma once

#include "create_solver_strategy.h"
#include "../benchmarks/golomb_ruler.h"

class ForGolombRulerCSS : public CreateSolverStrategy
{
    public:
        ForGolombRulerCSS(GolombRuler * golomb);
        vector<POSL_Solver *> create();

    private:
        POSL_Solver * single_solver;
        POSL_Solver * receiver_solver;
        POSL_Solver * sender_solver;
};
