#pragma once

#include "posl_solver.h"
#include "../connections/scheduler.h"
#include "../connections/connection_operator.h"

class POSL_MetaSolver
{
    public:
        POSL_MetaSolver(std::string path, int _comm_size, std::shared_ptr<Benchmark> bench, std::string _exe_path);
        POSL_MetaSolver(std::string path, int _comm_size, std::shared_ptr<Benchmark> bench);
        void solve_in_parallel();
        void solve_sequentially();
        std::string test(std::shared_ptr<PSP> psp);

    private:
        int comm_size;
        std::shared_ptr<Scheduler> scheduler;
        std::shared_ptr<Benchmark> benchmark;
        std::string exe_path;
};
