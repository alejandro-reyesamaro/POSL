#include "speed_operator.h"
#include "../computation/not_implemented_parallel_strategy.h"
#include "../computation/speed_sequential_strategy.h"

SpeedOperator::SpeedOperator(CompoundModule *_M1, CompoundModule *_M2) :
    BinaryOperator(_M1, _M2, new SpeedSequentialStrategy(_M1, _M2), new NotImplementedParallelStrategy())
{}
