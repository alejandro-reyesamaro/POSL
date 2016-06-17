#include "om_always_improve_decision.h"
#include "../data/decision_pair.h"
#include "../tools/tokens_definition.h"
#include "../tools/tools.h"

#include <iostream>
using namespace std;

OM_AlwaysImproveDecision::OM_AlwaysImproveDecision()
    : cost(-1)
{
}

shared_ptr<Solution> OM_AlwaysImproveDecision::spcf_execute(shared_ptr<PSP> psp, shared_ptr<DecisionPair> input)
{
    psp->UpdateSolution(input->GetFound()->get_conf_by_ref());
    // <debug code>
    /*
    vector<int> found = input->GetFound()->get_conf_by_copy();
    int current_cost = psp->CurrentCost();
    int best_cost = psp->BestCostSoFar();
    if(psp->CurrentCost() != cost)
    {
        cost = psp->CurrentCost();
        cout << "om_always_improve_decision.cpp" << psp->GetIterations() << " - " << cost << " - " << psp->BestCostSoFar() << endl;
        cout << psp->GetBestSolutionSoFar()->configurationToString() << endl;
    }
    //cout << input->GetFound()->configurationToString() << endl;
    */
    // </debug code>
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
