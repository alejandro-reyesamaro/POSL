#include "aom_decision_function.h"

shared_ptr<ComputationData> AOM_DecisionFunction::execute(shared_ptr<PSP> psp, shared_ptr<ComputationData> input)
{
    return spcf_execute(psp, static_pointer_cast<DecisionPair>(input));
}
