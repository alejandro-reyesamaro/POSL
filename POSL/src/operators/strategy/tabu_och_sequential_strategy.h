#pragma once

#include "sequential_execution_strategy.h"
#include "../../expressions/iteretion_bound_expression.h"
#include "../../modules/open_channel.h"

class TabuOChSequentialStrategy : public SequentialExecutionStrategy
{
    public:
        TabuOChSequentialStrategy(std::shared_ptr<OpenChannel> _OCH);

        std::shared_ptr<ComputationData> evaluate(std::shared_ptr<PSP> psp, std::shared_ptr<ComputationData> input);

    private:
        std::shared_ptr<OpenChannel> OCh;
        std::shared_ptr<ComputationData> output;
};
