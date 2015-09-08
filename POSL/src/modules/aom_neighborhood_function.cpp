#include "aom_neighborhood_function.h"

shared_ptr<ComputationData> AOM_NeighborhoodFunction::execute(shared_ptr<PSP> psp, shared_ptr<ComputationData> input)
{
    return spcf_execute(psp, static_pointer_cast<Solution>(input));
}
