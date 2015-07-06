#include "om_fixed_first_configuration.h"

#include <random>
#include <iostream>

OM_FixedFirstConfiguration::OM_FixedFirstConfiguration()
{
}

ComputationData * OM_FixedFirstConfiguration::execute(PSP *psp, ComputationData * input)
{
    psp->UpdateSolution((Solution *)input);
    psp->UpdateBestSolution((Solution *)input);
    return (Solution *) input;
}
