#include "oms_iterations_counter.h"

#include <iostream>
using namespace std;

OMS_IterationsCounter::OMS_IterationsCounter()
{}

ComputationData * OMS_IterationsCounter::execute(PSP *psp, ComputationData * input)
{
    psp->CountIteration();
    //cout << "Iteration counted: " << psp->GetIterations() << endl;
    return input;
}

string OMS_IterationsCounter::codeToSend()
{
    return "S2";
}
