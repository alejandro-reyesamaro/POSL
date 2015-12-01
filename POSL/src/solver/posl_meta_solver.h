#pragma once

#include "posl_solver.h"
#include "../connections/scheduler.h"

class POSL_MetaSolver
{
    public:
        // A eliminar
        POSL_MetaSolver(std::vector<std::shared_ptr<POSL_Solver>> _solvers);
        void solve(int argc, char **argv, std::shared_ptr<Benchmark> bench, unsigned int opt);
        //------


        POSL_MetaSolver(std::string code, int _comm_size, std::shared_ptr<Benchmark> bench);
        void solve(int argc, char **argv, std::shared_ptr<Benchmark> bench);



    private:
        std::shared_ptr<Scheduler> scheduler;
        int comm_size;



        //void solve_MS(int argc, char **argv, shared_ptr<Benchmark> bench);
        void solve_Default_NO(int argc, char **argv, std::shared_ptr<Benchmark> bench);
        void solve_Default_50(int argc, char **argv, std::shared_ptr<Benchmark> bench, int factor);
        void solve_Default_All(int argc, char **argv, std::shared_ptr<Benchmark> bench);
        std::vector<std::shared_ptr<POSL_Solver>> solvers;
};
