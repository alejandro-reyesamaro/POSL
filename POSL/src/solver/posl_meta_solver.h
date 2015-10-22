#pragma once

#include "posl_solver.h"

class POSL_MetaSolver
{
    public:
        POSL_MetaSolver(std::vector<std::shared_ptr<POSL_Solver>> _solvers);

        void solve(int argc, char **argv, std::shared_ptr<Benchmark> bench, unsigned int opt);

    private:
        //void solve_MS(int argc, char **argv, shared_ptr<Benchmark> bench);
        void solve_Default_NO(int argc, char **argv, std::shared_ptr<Benchmark> bench);
        void solve_Default_50(int argc, char **argv, std::shared_ptr<Benchmark> bench, int factor);
        void solve_Default_All(int argc, char **argv, std::shared_ptr<Benchmark> bench);
        std::vector<std::shared_ptr<POSL_Solver>> solvers;
};
