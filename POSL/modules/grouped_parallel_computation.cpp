#include "grouped_parallel_computation.h"

GroupedParallelComputation::GroupedParallelComputation(Operator * _op)
    : GroupedComputation(_op)
{
}

ComputationData * GroupedParallelComputation::execute(Benchmark * bench, ComputationData * input)
{
    return op->evaluateInParallel(bench, input);
}
