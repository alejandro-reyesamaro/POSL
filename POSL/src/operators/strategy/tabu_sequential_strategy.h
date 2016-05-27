#pragma once

#include "sequential_execution_strategy.h"
#include "../../expressions/iteretion_bound_expression.h"

class TabuSequentialStrategy : public SequentialExecutionStrategy
{
    public:
        TabuSequentialStrategy(std::shared_ptr<CompoundModule> _M1);

        std::shared_ptr<ComputationData> evaluate(std::shared_ptr<PSP> psp, std::shared_ptr<ComputationData> input);

    private:
        std::shared_ptr<CompoundModule> M1;
        std::shared_ptr<ComputationData> output;
};
