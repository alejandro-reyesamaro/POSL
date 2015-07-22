#include "union_operator.h"
#include "../computation/union_parallel_strategy.h"
#include "../computation/union_sequential_strategy.h"

UnionOperator::UnionOperator(CompoundModule *_M1, CompoundModule *_M2) :
    BinaryOperator(_M1, _M2, new UnionSequentialStrategy(_M1, _M2), new UnionParallelStrategy(_M1, _M2))
{}
