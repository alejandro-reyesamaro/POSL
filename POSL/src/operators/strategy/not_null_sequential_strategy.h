#pragma once

#include "sequential_execution_strategy.h"
#include "../../modules/open_channel.h"

class NotNullSequentialStrategy : public SequentialExecutionStrategy
{
    public:
        NotNullSequentialStrategy(std::shared_ptr<OpenChannel> _OCH, std::shared_ptr<CompoundModule> _M);

        std::shared_ptr<ComputationData> evaluate(std::shared_ptr<PSP> psp, std::shared_ptr<ComputationData> input);

    private:
        std::shared_ptr<OpenChannel> Och;
        std::shared_ptr<CompoundModule> M;

        std::shared_ptr<ComputationData> result_och;
        std::shared_ptr<ComputationData> result_m;
};

