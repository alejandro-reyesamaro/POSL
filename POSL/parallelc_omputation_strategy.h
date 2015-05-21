#pragma once

#include "computation_strategy.h"

template <typename IN, typename OUT>
class ParallelComputationStrategy : ComputationStrategy
{
    public:
        virtual OUT evaluate(IN input) = 0;
};
