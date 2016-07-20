#pragma once

#include <string>
#include <memory>

#include "../../benchmarks/benchmark.h"
#include "../psp.h"

class ShowingResultStrategy
{
    public:
        virtual std::string show(std::shared_ptr<PSP> psp,
                                 std::shared_ptr<Benchmark> bench,
                                 std::shared_ptr<Solution> best_solution,
                                 int best_cost,
                                 std::shared_ptr<Solution> final_solution,
                                 int final_cost,
                                 std::string strategy_tag,
                                 int iterations,
                                 int time) = 0;
};

