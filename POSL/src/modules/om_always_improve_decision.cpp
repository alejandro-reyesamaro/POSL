#include "om_always_improve_decision.h"
#include "../data/decision_pair.h"
#include "../tools/tokens_definition.h"

#include <iostream>
using namespace std;

OM_AlwaysImproveDecision::OM_AlwaysImproveDecision()
{
}

shared_ptr<Solution> OM_AlwaysImproveDecision::spcf_execute(shared_ptr<PSP> psp, shared_ptr<DecisionPair> input)
{
    psp->UpdateSolution(input->GetFound()->GetConfiguration());
    //cout << "OM_SS" << endl;
    return input->GetFound();
}

string OM_AlwaysImproveDecision::codeToSend()
{
    return OM_ALWAYS_IMPROVEMENT_DECISION_TOK;
}

string OM_AlwaysImproveDecision::Tag()
{
    return "Improving_Decision";
}
