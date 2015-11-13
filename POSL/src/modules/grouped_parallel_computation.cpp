#include "grouped_parallel_computation.h"

GroupedParallelComputation::GroupedParallelComputation(std::shared_ptr<Operator> _op)
    : GroupedComputation(_op)
{
}

std::shared_ptr<ComputationData> GroupedParallelComputation::execute(std::shared_ptr<PSP> psp, std::shared_ptr<ComputationData> input)
{
    return op->evaluateInParallel(psp, input);
}

std::string GroupedParallelComputation::codeToSend()
{
    return "<P>" + op->codeToSend() + "<P>";
}
