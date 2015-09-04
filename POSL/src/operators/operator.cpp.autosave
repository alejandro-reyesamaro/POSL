#include "operator.h"

#include <iostream>
using namespace std;

Operator::Operator(SequentialExecutionStrategy *_seq_strategy,
                   ParallelExecutionStrategy *_para_strategy):
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
