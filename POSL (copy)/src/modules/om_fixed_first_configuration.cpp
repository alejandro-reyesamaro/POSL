#include "om_fixed_first_configuration.h"

#include <random>
#include <iostream>

OM_FixedFirstConfiguration::OM_FixedFirstConfiguration()
{
}

ComputationData * OM_FixedFirstConfiguration::execute(PSP *psp, ComputationData * input)
{
    psp->UpdateSolution((Solution *)input);
    return (Solution *) input;
}

string OM_FixedFirstConfiguration::codeToSend()
{
    return "A1";
}
