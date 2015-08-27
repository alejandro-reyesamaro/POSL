#include "om_always_improve_decision.h"
#include "../data/decision_pair.h"

#include <iostream>
using namespace std;

OM_AlwaysImproveDecision::OM_AlwaysImproveDecision()
{
}

Solution * OM_AlwaysImproveDecision::spcf_execute(PSP * psp, DecisionPair * input)
{
    psp->UpdateSolution(input->GetFound());
    return input->GetFound();
}

string OM_AlwaysImproveDecision::codeToSend()
{
    return "D1";
}
