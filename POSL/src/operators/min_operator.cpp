#include "min_operator.h"
#include "strategy/min_sequential_strategy.h"
#include "strategy/min_parallel_strategy.h"
#include "../tools/tools.h"

MinOperator::MinOperator(shared_ptr<CompoundModule> _M1, shared_ptr<CompoundModule> _M2)
    : BinaryOperator(_M1, _M2, make_shared<MinSequentialStrategy>(_M1, _M2), make_shared<MinParallelStrategy>(_M1, _M2))
{}

string MinOperator::codeToSend()
{
    return "4 " + M1->codeToSend() + " " + M2->codeToSend();
}
