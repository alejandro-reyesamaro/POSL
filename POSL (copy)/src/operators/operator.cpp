#include "operator.h"

Operator::Operator(SequentialComputationStrategy *_seq_strategy,
                   ParallelComputationStrategy *_para_strategy):
    seq_strategy(_seq_strategy),
    para_strategy(_para_strategy)
{}

ComputationData * Operator::evaluateSequentially(PSP *psp, ComputationData * input)
{
    return seq_strategy->evaluate(psp, input);
}
ComputationData * Operator::evaluateInParallel(PSP *psp, ComputationData * input)
{
    return para_strategy->evaluate(psp, input);
}
