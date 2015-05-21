#pragma once

#include "operator.h"

class SequentialExecOperator : public Operator
{
    public:
        SequentialExecOperator(CompoundModule * _M1, CompoundModule * _M2);
        ComputationData * evaluateSequentially(Benchmark * bench, ComputationData * input);
        ComputationData * evaluateInParallel(Benchmark * bench, ComputationData * input);

    private:
        CompoundModule * M1;
        CompoundModule * M2;
};
