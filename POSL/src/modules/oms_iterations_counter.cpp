#include "oms_iterations_counter.h"

OMS_IterationsCounter::OMS_IterationsCounter()
{}

ComputationData * OMS_IterationsCounter::execute(PSP *psp, ComputationData * input)
{
    psp->CountIteration();
    return input;
}

string OMS_IterationsCounter::codeToSend()
{
    return "S2";
}
