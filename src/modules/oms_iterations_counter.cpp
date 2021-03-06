#include "oms_iterations_counter.h"
#include "../tools/tokens_definition.h"

#include <iostream>
using namespace std;

OMS_IterationsCounter::OMS_IterationsCounter()
{}

shared_ptr<ComputationData> OMS_IterationsCounter::execute(shared_ptr<PSP> psp, shared_ptr<ComputationData> input)
{
    psp->CountIteration();
    // <debug code>
    /*
    int current_cost = psp->CurrentCost();
    int best_cost = psp->BestCostSoFar();
    int it = psp->GetIterations();
    cout << psp->GetIterations() << ": " << psp->CurrentCost() << " - " << psp->BestCostSoFar() << endl;
    */
    // </debug code>
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
