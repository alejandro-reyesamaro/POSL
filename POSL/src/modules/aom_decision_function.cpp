#include "aom_decision_function.h"

ComputationData * AOM_DecisionFunction::execute(PSP * psp, ComputationData * input)
{
    return spcf_execute(psp, (DecisionPair *) input);
}
