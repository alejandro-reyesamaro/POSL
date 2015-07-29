#include "sequential_exec_operator.h"
#include "../computation/not_implemented_parallel_strategy.h"
#include "../computation/sequential_execution_sequential_strategy.h"

#include <iostream>

SequentialExecOperator::SequentialExecOperator(CompoundModule *_M1, CompoundModule *_M2) :
    BinaryOperator(_M1, _M2, new SequentialExecutionSequentialStrategy(_M1, _M2), new NotImplementedParallelStrategy())
{}

string SequentialExecOperator::codeToSend()
{
    return "4 " + M1->codeToSend() + " " + M2->codeToSend();
}
