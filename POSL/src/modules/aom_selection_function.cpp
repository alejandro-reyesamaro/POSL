#include "aom_selection_function.h"

ComputationData * AOM_SelectionFunction::execute(PSP * psp, ComputationData * input)
{
    return spcf_execute(psp, (Neighborhood *) input);
}
