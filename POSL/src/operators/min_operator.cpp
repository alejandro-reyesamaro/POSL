#include "min_operator.h"
#include "strategy/min_sequential_strategy.h"
#include "strategy/min_parallel_strategy.h"
#include "../tools/tools.h"

MinOperator::MinOperator(CompoundModule *_M1, CompoundModule *_M2)
    : BinaryOperator(_M1, _M2, new MinSequentialStrategy(_M1, _M2), new MinParallelStrategy(_M1, _M2))
{}

string MinOperator::codeToSend()
{
    return "4 " + M1->codeToSend() + " " + M2->codeToSend();
}
