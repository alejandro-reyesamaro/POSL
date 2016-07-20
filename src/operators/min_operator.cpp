#include "min_operator.h"
#include "strategy/min_sequential_strategy.h"
#include "strategy/min_och_sequential_strategy.h"
#include "strategy/min_parallel_strategy.h"
#include "../modules/open_channel.h"
#include "../tools/tools.h"
#include "../tools/tokens_definition.h"

#include <typeinfo>

using namespace std;

shared_ptr<SequentialExecutionStrategy> chose_sequential_strategy(shared_ptr<CompoundModule> _M1, shared_ptr<CompoundModule> _M2)
{
    if(_M1->Tag() == TAGOCh)
        return make_shared<MinOChSequentialStrategy>(static_pointer_cast<OpenChannel>(_M1), _M2);
    else if(_M2->Tag() == TAGOCh)
        return make_shared<MinOChSequentialStrategy>(static_pointer_cast<OpenChannel>(_M2), _M1);
    else return make_shared<MinSequentialStrategy>(_M1, _M2);
}


MinOperator::MinOperator(shared_ptr<CompoundModule> _M1, shared_ptr<CompoundModule> _M2)
    : BinaryOperator(_M1, _M2, chose_sequential_strategy(_M1, _M2), make_shared<MinParallelStrategy>(_M1, _M2)) // do the same in parallel
{}

string MinOperator::codeToSend()
{
    return string(OP_MIN_TOK) + " " + M1->codeToSend() + " " + M2->codeToSend();
}

