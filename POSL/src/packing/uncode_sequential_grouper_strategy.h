#pragma once

#include "../modules/grouped_sequential_computation.h"
#include "uncode_operator_strategy.h"

class UncodeSequentialGrouperStrategy
{
    public:
        UncodeSequentialGrouperStrategy();
        GroupedSequentialComputation * uncode(string code, Benchmark * bench);
};

