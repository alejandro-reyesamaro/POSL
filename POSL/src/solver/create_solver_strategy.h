#pragma once

#include "posl_solver.h"

class CreateSolverStrategy
{
    public:
        CreateSolverStrategy(shared_ptr<Benchmark> _bench);
        virtual vector<shared_ptr<POSL_Solver>> create() = 0;

    protected:
        shared_ptr<Benchmark> bench;
        vector<shared_ptr<POSL_Solver>> solvers;
};
