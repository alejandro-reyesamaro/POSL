#include "om_always_improve_decision.h"
#include "../data/decision_pair.h"

#include <iostream>
using namespace std;

OM_AlwaysImproveDecision::OM_AlwaysImproveDecision()
{
}

shared_ptr<Solution> OM_AlwaysImproveDecision::spcf_execute(shared_ptr<PSP> psp, shared_ptr<DecisionPair> input)
{
    psp->UpdateSolution(input->GetFound()->GetConfiguration());
    return input->GetFound();
}

string OM_AlwaysImproveDecision::codeToSend()
{
    return "D1";
}
