#include "oms_iterations_counter.h"
#include "../tools/tokens_definition.h"

#include <iostream>
using namespace std;

OMS_IterationsCounter::OMS_IterationsCounter()
{}

shared_ptr<ComputationData> OMS_IterationsCounter::execute(shared_ptr<PSP> psp, shared_ptr<ComputationData> input)
{
    psp->CountIteration();
    //cout << psp->GetIterations() << endl;
    return input;
}

string OMS_IterationsCounter::codeToSend()
{
    return OMS_ITERATIONS_COUNTER_TOK;
}

string OMS_IterationsCounter::Tag()
{
    return "Iterations counter";
}
