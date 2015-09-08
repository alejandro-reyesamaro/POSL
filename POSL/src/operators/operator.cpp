#include "operator.h"

#include <iostream>
using namespace std;

Operator::Operator(shared_ptr<SequentialExecutionStrategy> _seq_strategy,
                   shared_ptr<ParallelExecutionStrategy> _para_strategy):
    seq_strategy(_seq_strategy),
    para_strategy(_para_strategy)
{}

shared_ptr<ComputationData> Operator::evaluateSequentially(shared_ptr<PSP> psp, shared_ptr<ComputationData> input)
{
    return seq_strategy->evaluate(psp, input);
}
shared_ptr<ComputationData> Operator::evaluateInParallel(shared_ptr<PSP> psp, shared_ptr<ComputationData> input)
{
    return para_strategy->evaluate(psp, input);
}
