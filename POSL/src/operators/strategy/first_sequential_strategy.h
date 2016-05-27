#pragma once

#include "sequential_execution_strategy.h"

class FirstSequentialStrategy : public SequentialExecutionStrategy
{
    public:
        FirstSequentialStrategy(std::shared_ptr<CompoundModule> _M1, std::shared_ptr<CompoundModule> _M2);

        std::shared_ptr<ComputationData> evaluate(std::shared_ptr<PSP> psp, std::shared_ptr<ComputationData> input);

    private:
        std::shared_ptr<CompoundModule> M1;
        std::shared_ptr<CompoundModule> M2;

        std::shared_ptr<ComputationData> result_m1;
        std::shared_ptr<ComputationData> result_m2;
};
