#include "conditional_operator.h"
#include "../computation/not_implemented_parallel_strategy.h"
#include "../computation/conditional_sequential_strategy.h"

ConditionalOperator::ConditionalOperator(CompoundModule * _M1, CompoundModule * _M2, BooleanExpression * ex):
    BinaryOperator(_M1, _M2, new ConditionalSequentialStrategy(_M1, _M2, ex), new NotImplementedParallelStrategy())
{}
