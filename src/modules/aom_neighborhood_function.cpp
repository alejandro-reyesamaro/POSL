#include "aom_neighborhood_function.h"

std::shared_ptr<ComputationData> AOM_NeighborhoodFunction::execute(std::shared_ptr<PSP> psp, std::shared_ptr<ComputationData> input)
{
    return spcf_execute(psp, std::static_pointer_cast<Solution>(input));
}
