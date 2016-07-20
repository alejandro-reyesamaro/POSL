#pragma once

#include "posl_solver.h"

class CreateSolverStrategy
{
    public:
        CreateSolverStrategy(std::shared_ptr<Benchmark> _bench);
        virtual std::vector<std::shared_ptr<POSL_Solver>> create() = 0;

    protected:
        std::shared_ptr<Benchmark> bench;
        std::vector<std::shared_ptr<POSL_Solver>> solvers;
};
