#include "om_fixed_first_configuration.h"

#include <random>
#include <iostream>

OM_FixedFirstConfiguration::OM_FixedFirstConfiguration(std::shared_ptr<Benchmark> bench)
    : AOM_FirstConfigurationGeneration(bench)
{}

std::shared_ptr<Solution> OM_FixedFirstConfiguration::spcf_execute(std::shared_ptr<PSP> psp, std::shared_ptr<Solution> input)
{
    psp->UpdateSolution(input->GetConfiguration());
    return input;
}

std::string OM_FixedFirstConfiguration::codeToSend()
{
    return "A1";
}
