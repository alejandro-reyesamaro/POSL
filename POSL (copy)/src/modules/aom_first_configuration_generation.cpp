#include "aom_first_configuration_generation.h"

ComputationData * AOM_FirstConfigurationGeneration::execute(PSP * psp, ComputationData * input)
{
    return spcf_execute(psp, (Solution *) input);
}
