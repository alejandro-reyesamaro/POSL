#include "oms_iterations_counter.h"

#include <iostream>
using namespace std;

OMS_IterationsCounter::OMS_IterationsCounter()
{}

shared_ptr<ComputationData> OMS_IterationsCounter::execute(shared_ptr<PSP> psp, shared_ptr<ComputationData> input)
{
    psp->CountIteration();
    //cout << "Iteration counted: " << psp->GetIterations() << endl;
    return input;
}

string OMS_IterationsCounter::codeToSend()
{
    return "S2";
}

string OMS_IterationsCounter::Tag()
{
    return "Iterations counter";
}
