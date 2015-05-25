#include "om_fixed_first_configuration.h"

#include <random>
#include <iostream>

OM_FixedFirstConfiguration::OM_FixedFirstConfiguration()
{
}

ComputationData * OM_FixedFirstConfiguration::execute(Benchmark * bench, ComputationData * input)
{
    bench->UpdateSolution((Solution *)input);
    return (Solution *) input;
}
