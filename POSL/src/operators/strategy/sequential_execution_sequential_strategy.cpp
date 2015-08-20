#include "sequential_execution_sequential_strategy.h"

#include <iostream>
using namespace std;

SequentialExecutionSequentialStrategy::SequentialExecutionSequentialStrategy(CompoundModule *_M1, CompoundModule *_M2) : M1(_M1), M2(_M2)
{
}

ComputationData * SequentialExecutionSequentialStrategy::evaluate(PSP *psp, ComputationData * input)
{
    //cout << "Inside Sequential Operator (strategy)" << endl;
    ComputationData * io = M1->execute(psp, input);
    ComputationData * result = M2->execute(psp, io);
    //cout << "Inside Sequential Operator (strategy) - DONE" << endl;
    return result;
}
