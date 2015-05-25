#pragma once

#include "computation_data.h"
#include "solution.h"

class DecisionPair : public ComputationData
{
    public:
        DecisionPair(Solution * _current, Solution * _found);
        Solution * current;
        Solution * found;
        bool equals();
};
