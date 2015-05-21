#include "operator.h"

Operator::Operator(SequentialComputationStrategy *_seq_strategy,
                   ParallelComputationStrategy *_para_strategy):
    seq_strategy(_seq_strategy),
    para_strategy(_para_strategy)
{}
