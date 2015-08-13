#include "unary_operator.h"
#include "../computation/not_implemented_parallel_strategy.h"

UnaryOperator::UnaryOperator(CompoundModule *_M1, SequentialExecutionStrategy *seq_strgy) :
    Operator(seq_strgy, new NotImplementedParallelStrategy()), M1(_M1)
{}
