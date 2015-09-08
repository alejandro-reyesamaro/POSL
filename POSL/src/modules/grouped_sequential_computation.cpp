#include "grouped_sequential_computation.h"

#include <iostream>
using namespace std;

GroupedSequentialComputation::GroupedSequentialComputation(shared_ptr<Operator> _op)
    : GroupedComputation(_op)
{
}

shared_ptr<ComputationData> GroupedSequentialComputation::execute(shared_ptr<PSP> psp, shared_ptr<ComputationData> input)
{
    //cout << "Inside GroupedSequentialComputation" << endl;
    return op->evaluateSequentially(psp, input);
}

string GroupedSequentialComputation::codeToSend()
{
    return "{" + op->codeToSend() + "}";
}
