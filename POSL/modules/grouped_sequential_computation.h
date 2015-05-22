#pragma once

#include "grouped_computation.h"

class GroupedSequentialComputation : public GroupedComputation
{
    public:
        GroupedSequentialComputation(Operator * _op);
        ComputationData * execute(Benchmark * bench, ComputationData * input);
};
