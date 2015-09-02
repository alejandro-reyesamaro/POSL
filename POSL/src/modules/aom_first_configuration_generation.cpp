#include "aom_first_configuration_generation.h"

AOM_FirstConfigurationGeneration::AOM_FirstConfigurationGeneration(vector<Domain> _domains)
    : domains(_domains)
{}

ComputationData * AOM_FirstConfigurationGeneration::execute(PSP * psp, ComputationData * input)
{
    return spcf_execute(psp, (Solution *) input);
}
