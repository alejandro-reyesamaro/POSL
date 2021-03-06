#include "conditional_operator.h"
#include "strategy/not_implemented_parallel_strategy.h"
#include "strategy/conditional_sequential_strategy.h"
#include "../tools/tokens_definition.h"

using namespace std;

ConditionalOperator::ConditionalOperator(shared_ptr<CompoundModule> _M1, shared_ptr<CompoundModule> _M2, shared_ptr<BooleanExpression> _ex)
    : BinaryOperator(_M1, _M2, make_shared<ConditionalSequentialStrategy>(_M1, _M2, _ex), make_shared<NotImplementedParallelStrategy>()),
      ex(_ex)
{}

string ConditionalOperator::codeToSend()
{
    return string(OP_CONDITIONAL_EXECUTION_TOK) + " (" + ex->codeToSend() + ") " + M1 ->codeToSend() + " " + M2->codeToSend();
}
