#include "om_always_improve_decition.h"
#include "../data/decision_pair.h"

#include <iostream>
using namespace std;

OM_AlwaysImproveDecition::OM_AlwaysImproveDecition()
{
}

ComputationData * OM_AlwaysImproveDecition::execute(PSP *psp, ComputationData * input)
{
    //cout << "OM Always Improv Decission" << endl;
    DecisionPair * pair = (DecisionPair *) input;
    psp->UpdateSolution(pair->GetFound());
    //cout << "OM Always Improv Decission - DONE" << endl;
    return pair->GetFound();
}

string OM_AlwaysImproveDecition::codeToSend()
{
    return "D1";
}
