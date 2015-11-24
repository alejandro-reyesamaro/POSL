#include "speed_operator.h"
#include "strategy/speed_parallel_strategy.h"
#include "strategy/speed_sequential_strategy.h"
#include "../tools/tokens_definition.h"

SpeedOperator::SpeedOperator(shared_ptr<CompoundModule> _M1, shared_ptr<CompoundModule> _M2) :
    BinaryOperator(_M1, _M2, make_shared<SpeedSequentialStrategy>(_M1, _M2), make_shared<SpeedParallelStrategy>(_M1, _M2))
{}

string SpeedOperator::codeToSend()
{
    return string(OP_SPEED_TOK) + " " + M1->codeToSend() + " " + M2->codeToSend();
}
