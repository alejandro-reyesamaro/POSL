#include "sequential_exec_operator.h"
#include "not_implemented_parallel_strategy.h"
#include "sequential_execution_sequential_strategy.h"

SequentialExecOperator::SequentialExecOperator(CompoundModule *_M1, CompoundModule *_M2) :
    Operator(new SequentialExecutionSequentialStrategy(_M1, _M2), new NotImplementedParallelStrategy())

{

}

ComputationData * SequentialExecOperator::evaluateSequentially(Benchmark * bench, ComputationData * input)
{
    return seq_strategy->evaluate(bench, input);
}
ComputationData * SequentialExecOperator::evaluateInParallel(Benchmark * bench, ComputationData * input)
{
    return para_strategy->evaluate(bench, input);
}
