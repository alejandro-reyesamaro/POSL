#include "sequential_execution_sequential_strategy.h"

SequentialExecutionSequentialStrategy::SequentialExecutionSequentialStrategy(CompoundModule *_M1, CompoundModule *_M2) : M1(_M1), M2(_M2)
{
}

ComputationData * SequentialExecutionSequentialStrategy::evaluate(Benchmark * bench, ComputationData * input)
{
    ComputationData * io = M1->execute(bench, input);
    return M2->execute(bench, io);
}
