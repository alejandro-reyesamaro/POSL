#pragma once

#include "posl_solver.h"

class POSL_MetaSolver
{
    public:
        POSL_MetaSolver();//vector<POSL_Solver *> _solvers);

        void solve(int argc, char **argv, Benchmark *bench);

    private:
        void solve_MS(int argc, char **argv, Benchmark * bench);
        vector<POSL_Solver *> solvers;        
};
