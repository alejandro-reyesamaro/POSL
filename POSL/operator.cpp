#include "operator.h"

Operator::Operator(shared_ptr<ComputationStrategy> _seq_strategy,
                   shared_ptr<ComputationStrategy> _para_strategy):
    seq_strategy(_seq_strategy),
    para_strategy(_para_strategy)
{}
