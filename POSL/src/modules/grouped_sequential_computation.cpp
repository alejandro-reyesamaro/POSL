#include "grouped_sequential_computation.h"

GroupedSequentialComputation::GroupedSequentialComputation(Operator * _op)
    : GroupedComputation(_op)
{
}

ComputationData * GroupedSequentialComputation::execute(PSP * psp, ComputationData * input)
{
    return op->evaluateSequentially(psp, input);
}

string GroupedSequentialComputation::codeToSend()
{
    return "{" + op->codeToSend() + "}";
}
