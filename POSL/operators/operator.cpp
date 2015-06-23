#include "operator.h"

Operator::Operator(SequentialComputationStrategy *_seq_strategy,
                   ParallelComputationStrategy *_para_strategy):
    seq_strategy(_seq_strategy),
    para_strategy(_para_strategy)
{}

ComputationData * Operator::evaluateSequentially(Benchmark * bench, ComputationData * input)
{
    return seq_strategy->evaluate(bench, input);
}
ComputationData * Operator::evaluateInParallel(Benchmark * bench, ComputationData * input)
{
    return para_strategy->evaluate(bench, input);
}
