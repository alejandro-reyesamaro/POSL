#include "operator.h"

#include <iostream>
using namespace std;

Operator::Operator(SequentialComputationStrategy *_seq_strategy,
                   ParallelComputationStrategy *_para_strategy):
    seq_strategy(_seq_strategy),
    para_strategy(_para_strategy)
{}

ComputationData * Operator::evaluateSequentially(PSP *psp, ComputationData * input)
{
    //cout << "Inside Operator (abstract)" << endl;
    return seq_strategy->evaluate(psp, input);
}
ComputationData * Operator::evaluateInParallel(PSP *psp, ComputationData * input)
{
    return para_strategy->evaluate(psp, input);
}
