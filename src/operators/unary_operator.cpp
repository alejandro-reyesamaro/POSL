#include "unary_operator.h"
#include "strategy/not_implemented_parallel_strategy.h"

using namespace std;

UnaryOperator::UnaryOperator(shared_ptr<CompoundModule> _M1, shared_ptr<SequentialExecutionStrategy> seq_strgy) :
    Operator(seq_strgy, make_shared<NotImplementedParallelStrategy>()), M1(_M1)
{}
