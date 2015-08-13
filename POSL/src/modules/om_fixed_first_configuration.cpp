#include "om_fixed_first_configuration.h"

#include <random>
#include <iostream>

OM_FixedFirstConfiguration::OM_FixedFirstConfiguration()
{
}

Solution * OM_FixedFirstConfiguration::spcf_execute(PSP *psp, Solution * input)
{
    psp->UpdateSolution(input);
    return input;
}

string OM_FixedFirstConfiguration::codeToSend()
{
    return "A1";
}
