#pragma once

#include "posl_solver.h"

class POSL_MetaSolver
{
    public:
        POSL_MetaSolver();//vector<POSL_Solver *> _solvers);

        void solve(int argc, char **argv, Benchmark *bench);

    private:
        vector<POSL_Solver *> solvers;        
};
