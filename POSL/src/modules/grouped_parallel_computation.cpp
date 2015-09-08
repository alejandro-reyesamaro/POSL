#include "grouped_parallel_computation.h"

GroupedParallelComputation::GroupedParallelComputation(shared_ptr<Operator> _op)
    : GroupedComputation(_op)
{
}

shared_ptr<ComputationData> GroupedParallelComputation::execute(shared_ptr<PSP> psp, shared_ptr<ComputationData> input)
{
    return op->evaluateInParallel(psp, input);
}

string GroupedParallelComputation::codeToSend()
{
    return "[" + op->codeToSend() + "]";
}
