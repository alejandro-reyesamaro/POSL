#include "aom_selection_function.h"

shared_ptr<ComputationData> AOM_SelectionFunction::execute(shared_ptr<PSP> psp, shared_ptr<ComputationData> input)
{
    return spcf_execute(psp, static_pointer_cast<Neighborhood>(input));
}
