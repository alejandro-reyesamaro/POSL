#include "grouped_parallel_computation.h"

GroupedParallelComputation::GroupedParallelComputation(Operator * _op)
    : GroupedComputation(_op)
{
}

ComputationData * GroupedParallelComputation::execute(PSP *psp, ComputationData * input)
{
    return op->evaluateInParallel(psp, input);
}

string GroupedParallelComputation::codeToSend()
{
    return "[" + op->codeToSend() + "]";
}
