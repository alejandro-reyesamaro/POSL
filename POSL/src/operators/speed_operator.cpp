#include "speed_operator.h"
#include "strategy/speed_parallel_strategy.h"
#include "strategy/speed_sequential_strategy.h"

SpeedOperator::SpeedOperator(CompoundModule *_M1, CompoundModule *_M2) :
    BinaryOperator(_M1, _M2, new SpeedSequentialStrategy(_M1, _M2), new SpeedParallelStrategy(_M1, _M2))
{}

string SpeedOperator::codeToSend()
{
    return "5 " + M1->codeToSend() + " " + M2->codeToSend();
}
