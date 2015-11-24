#include "union_operator.h"
#include "strategy/union_parallel_strategy.h"
#include "strategy/union_sequential_strategy.h"
#include "../tools/tokens_definition.h"

using namespace std;

UnionOperator::UnionOperator(shared_ptr<CompoundModule> _M1, shared_ptr<CompoundModule> _M2) :
    BinaryOperator(_M1, _M2, make_shared<UnionSequentialStrategy>(_M1, _M2), make_shared<UnionParallelStrategy>(_M1, _M2))
{}

string UnionOperator::codeToSend()
{
    return string(OP_UNION_TOK) + " " + M1->codeToSend() + " " + M2->codeToSend();
}
