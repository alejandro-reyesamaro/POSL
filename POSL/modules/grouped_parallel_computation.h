#pragma once

#include "grouped_computation.h"

class GroupedParallelComputation : public GroupedComputation
{
    public:
        GroupedParallelComputation(Operator * _op);
        ComputationData * execute(Benchmark * bench, ComputationData * input);
};
