#pragma once

#include "../../connections/scheduler.h"

class SolveSequentiallyStrategy
{
    public:
        SolveSequentiallyStrategy(std::shared_ptr<Benchmark> bench);

        std::string solve(shared_ptr<Scheduler> scheduler);//, shared_ptr<SearchProcessParamsStruct> psp_params);

    private:
        std::shared_ptr<Benchmark> benchmark;
};
