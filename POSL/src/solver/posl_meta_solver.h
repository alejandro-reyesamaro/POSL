#pragma once

#include "posl_solver.h"
#include "../connections/scheduler.h"
#include "../connections/connection_operator.h"


class POSL_MetaSolver
{
    public:
        // A eliminar
        //POSL_MetaSolver(std::vector<std::shared_ptr<POSL_Solver>> _solvers);
        //void solve(int argc, char **argv, std::shared_ptr<Benchmark> bench, unsigned int opt);
        //------


        POSL_MetaSolver(std::string path, int _comm_size, std::shared_ptr<Benchmark> bench);
        void solve_in_parallel();
        void solve_sequentially();



    private:
        int comm_size;
        std::shared_ptr<Scheduler> scheduler;
        //std::vector<std::shared_ptr<ConnectionOperator>> connection_operators;
        std::shared_ptr<Benchmark> benchmark;



        //void solve_MS(int argc, char **argv, shared_ptr<Benchmark> bench);
        //void solve_Default_NO(int argc, char **argv, std::shared_ptr<Benchmark> bench);
        //void solve_Default_50(int argc, char **argv, std::shared_ptr<Benchmark> bench, int factor);
        //void solve_Default_All(int argc, char **argv, std::shared_ptr<Benchmark> bench);
        //std::vector<std::shared_ptr<POSL_Solver>> solvers;
};
