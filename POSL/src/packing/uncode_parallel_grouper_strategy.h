#pragma once

#include "../modules/grouped_parallel_computation.h"
#include "uncode_operator_strategy.h"

class UncodeParallelGrouperStrategy
{
    public:
        UncodeParallelGrouperStrategy();
        GroupedParallelComputation * uncode(string code);
};
