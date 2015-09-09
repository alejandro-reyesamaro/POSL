#pragma once

#include "posl_solver.h"

class POSL_MetaSolver
{
    public:
        POSL_MetaSolver(std::vector<std::shared_ptr<POSL_Solver>> _solvers);

        void solve(int argc, char **argv, std::shared_ptr<Benchmark> bench);

    private:
        //void solve_MS(int argc, char **argv, shared_ptr<Benchmark> bench);
        void solve_Default(int argc, char **argv, std::shared_ptr<Benchmark> bench);
        std::vector<std::shared_ptr<POSL_Solver>> solvers;
};
