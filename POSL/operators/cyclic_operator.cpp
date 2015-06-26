#include "cyclic_operator.h"
#include "computation/cyclic_sequential_strategy.h"

CyclicOperator::CyclicOperator(CompoundModule * _M1, BooleanExpression * ex) :
    UnaryOperator(_M1, new CyclicSequentialStrategy(_M1, ex))
{}
