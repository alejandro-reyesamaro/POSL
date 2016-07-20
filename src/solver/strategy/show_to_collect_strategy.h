#pragma once

#include "showing_result_strategy.h"

class ShowToCollectStrategy : public ShowingResultStrategy
{
    public:
        ShowToCollectStrategy();
        std::string show(std::shared_ptr<PSP> psp, std::shared_ptr<Benchmark>,
                         std::shared_ptr<Solution> best_solution,
                         int best_cost,
                         std::shared_ptr<Solution> final_solution, int,
                         std::string strategy_tag,
                         int iterations,
                         int time);
};
