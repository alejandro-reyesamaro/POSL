#include "om_always_improve_decition.h"
#include "data/decision_pair.h"

OM_AlwaysImproveDecition::OM_AlwaysImproveDecition()
{
}

ComputationData * OM_AlwaysImproveDecition::execute(PSP *psp, ComputationData * input)
{
    DecisionPair * pair = (DecisionPair *) input;
    return pair->GetFound();
}
