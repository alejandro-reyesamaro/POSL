#pragma once

#include "posl_solver.h"

class CreateSolverStrategy
{
    public:
        CreateSolverStrategy(Benchmark * _bench);
        virtual vector<POSL_Solver *> create() = 0;

    protected:
        Benchmark * bench;
        vector<POSL_Solver *> solvers;
};
