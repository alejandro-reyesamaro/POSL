#pragma once

#include "computation_strategy.h"

template <typename IN, typename OUT>
class SequentialComputationStrategy : ComputationStrategy
{
    public:
        virtual OUT evaluate(IN input) = 0;
};
