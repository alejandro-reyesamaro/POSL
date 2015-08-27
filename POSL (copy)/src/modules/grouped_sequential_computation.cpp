#include "grouped_sequential_computation.h"

#include <iostream>
using namespace std;

GroupedSequentialComputation::GroupedSequentialComputation(Operator * _op)
    : GroupedComputation(_op)
{
}

ComputationData * GroupedSequentialComputation::execute(PSP * psp, ComputationData * input)
{
    //cout << "Inside GroupedSequentialComputation" << endl;
    return op->evaluateSequentially(psp, input);
}

string GroupedSequentialComputation::codeToSend()
{
    return "{" + op->codeToSend() + "}";
}
