#pragma once

#include "../../connections/scheduler.h"

class SolveToTestStrategy
{
    public:
        SolveToTestStrategy(std::shared_ptr<Benchmark> bench);

        std::string solve(shared_ptr<Scheduler> scheduler, shared_ptr<PSP> psp);

    private:
        std::shared_ptr<Benchmark> benchmark;
};
