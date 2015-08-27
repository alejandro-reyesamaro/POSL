#include "aom_neighborhood_function.h"

ComputationData * AOM_NeighborhoodFunction::execute(PSP * psp, ComputationData * input)
{
    return spcf_execute(psp, (Solution *) input);
}
