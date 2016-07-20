#include "grouped_sequential_computation.h"

#include <iostream>
using namespace std;

GroupedSequentialComputation::GroupedSequentialComputation(shared_ptr<Operator> _op)
    : GroupedComputation(_op)
{
}

shared_ptr<ComputationData> GroupedSequentialComputation::execute(shared_ptr<PSP> psp, shared_ptr<ComputationData> input)
{
    return op->evaluateSequentially(psp, input);
}

string GroupedSequentialComputation::codeToSend()
{
    return "<S>" + op->codeToSend() + "</S>";
}
