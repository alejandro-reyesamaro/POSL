#include "first_operator.h"
#include "strategy/first_sequential_strategy.h"
#include "strategy/not_implemented_parallel_strategy.h"
#include "../tools/tools.h"
#include "../tools/tokens_definition.h"

using namespace std;

FirstOperator::FirstOperator(shared_ptr<CompoundModule> _M1, shared_ptr<CompoundModule> _M2)
    : BinaryOperator(_M1, _M2, make_shared<FirstSequentialStrategy>(_M1, _M2), make_shared<NotImplementedParallelStrategy>())
{}

string FirstOperator::codeToSend()
{
    return string(OP_FIRST_TOK) + " " + M1->codeToSend() + " " + M2->codeToSend(); //"OP.First"
}
