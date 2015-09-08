#include "om_fixed_first_configuration.h"

#include <random>
#include <iostream>

OM_FixedFirstConfiguration::OM_FixedFirstConfiguration(shared_ptr<Benchmark> bench)
    : AOM_FirstConfigurationGeneration(bench)
{}

shared_ptr<Solution> OM_FixedFirstConfiguration::spcf_execute(shared_ptr<PSP> psp, shared_ptr<Solution> input)
{
    psp->UpdateSolution(input);
    return input;
}

string OM_FixedFirstConfiguration::codeToSend()
{
    return "A1";
}
