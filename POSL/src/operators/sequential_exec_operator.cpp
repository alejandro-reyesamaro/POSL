#include "sequential_exec_operator.h"
#include "strategy/not_implemented_parallel_strategy.h"
#include "strategy/sequential_execution_sequential_strategy.h"

#include <iostream>

using namespace std;

SequentialExecOperator::SequentialExecOperator(shared_ptr<CompoundModule> _M1, shared_ptr<CompoundModule> _M2) :
    BinaryOperator(_M1, _M2, make_shared<SequentialExecutionSequentialStrategy>(_M1, _M2), make_shared<NotImplementedParallelStrategy>())
{}

string SequentialExecOperator::codeToSend()
{
    return "OP.|-> " + M1->codeToSend() + " " + M2->codeToSend();
}
