#include "aom_selection_function.h"

std::shared_ptr<ComputationData> AOM_SelectionFunction::execute(std::shared_ptr<PSP> psp, std::shared_ptr<ComputationData> input)
{
    return spcf_execute(psp, std::static_pointer_cast<Neighborhood>(input));
}
