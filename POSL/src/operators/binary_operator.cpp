#include "binary_operator.h"

BinaryOperator::BinaryOperator(
        CompoundModule *_M1,
        CompoundModule *_M2,
        SequentialComputationStrategy * seq_strgy,
        ParallelComputationStrategy * par_strgy) :
    Operator(seq_strgy, par_strgy), M1(_M1), M2(_M2)
{}
