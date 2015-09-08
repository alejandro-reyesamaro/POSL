#include "binary_operator.h"

BinaryOperator::BinaryOperator(shared_ptr<CompoundModule> _M1,
                               shared_ptr<CompoundModule> _M2,
                               shared_ptr<SequentialExecutionStrategy> seq_strgy,
                               shared_ptr<ParallelExecutionStrategy> par_strgy)
    : Operator(seq_strgy, par_strgy), M1(_M1), M2(_M2)
{}
