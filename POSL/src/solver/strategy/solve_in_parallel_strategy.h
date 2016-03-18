#pragma once

#include "../../connections/scheduler.h"

class SolveInParallelStrategy
{
    public:
        SolveInParallelStrategy(std::shared_ptr<Benchmark> bench, std::string _exe_path);

        std::string solve(shared_ptr<Scheduler> scheduler);

    private:
        std::shared_ptr<Benchmark> benchmark;
        std::string exe_path;
        //std::ofstream outfile;
};
