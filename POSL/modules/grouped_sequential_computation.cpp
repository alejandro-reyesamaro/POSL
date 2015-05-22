#include "grouped_sequential_computation.h"

GroupedSequentialComputation::GroupedSequentialComputation(Operator * _op)
    : GroupedComputation(_op)
{
}

ComputationData * GroupedSequentialComputation::execute(Benchmark * bench, ComputationData * input)
{
    return op->evaluateSequentially(bench, input);
}
