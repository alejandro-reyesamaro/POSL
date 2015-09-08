#include "union_operator.h"
#include "strategy/union_parallel_strategy.h"
#include "strategy/union_sequential_strategy.h"

UnionOperator::UnionOperator(shared_ptr<CompoundModule> _M1, shared_ptr<CompoundModule> _M2) :
    BinaryOperator(_M1, _M2, make_shared<UnionSequentialStrategy>(_M1, _M2), make_shared<UnionParallelStrategy>(_M1, _M2))
{}

string UnionOperator::codeToSend()
{
    return "6 " + M1->codeToSend() + " " + M2->codeToSend();
}
