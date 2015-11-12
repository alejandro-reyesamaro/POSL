#pragma once

#include "showing_result_strategy.h"

class ShowPlainResultStrategy : public ShowingResultStrategy
{
    public:
        ShowPlainResultStrategy();
        std::string show(std::shared_ptr<Benchmark> bench,
                         std::shared_ptr<Solution> best_solution,
                         int best_cost,
                         std::shared_ptr<Solution> final_solution,
                         int final_cost,
                         std::string strategy_tag,
                         int iterations,
                         int time);
};
