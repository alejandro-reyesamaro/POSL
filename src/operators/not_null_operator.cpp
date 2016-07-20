#include "not_null_operator.h"
#include "strategy/not_null_sequential_strategy.h"
#include "strategy/not_implemented_parallel_strategy.h"
#include "../modules/open_channel.h"
#include "../tools/tools.h"
#include "../tools/tokens_definition.h"

using namespace std;

shared_ptr<SequentialExecutionStrategy> not_null_chose_sequential_strategy(shared_ptr<CompoundModule> _M1, shared_ptr<CompoundModule> _M2)
{
    if(_M1->Tag() == TAGOCh && _M2->Tag() != TAGOCh)
        return make_shared<NotNullSequentialStrategy>(static_pointer_cast<OpenChannel>(_M1), _M2);
    else if(_M2->Tag() == TAGOCh && _M1->Tag() != TAGOCh)
        return make_shared<NotNullSequentialStrategy>(static_pointer_cast<OpenChannel>(_M2), _M1);
    else throw "(POSL Exception) assembling error (NotNullOperator)";
}

NotNullOperator::NotNullOperator(shared_ptr<CompoundModule> _M1, shared_ptr<CompoundModule> _M2)
    : BinaryOperator(_M1, _M2, not_null_chose_sequential_strategy(_M1, _M2), make_shared<NotImplementedParallelStrategy>())
{}

string NotNullOperator::codeToSend()
{
    return string(OP_NOTNULL_TOK) + " " + M1->codeToSend() + " " + M2->codeToSend();
}
