#include "om_fixed_first_configuration.h"

#include <random>
#include <iostream>

using namespace std;

OM_FixedFirstConfiguration::OM_FixedFirstConfiguration(shared_ptr<Benchmark> bench)
    : AOM_FirstConfigurationGeneration(bench)
{}

shared_ptr<Solution> OM_FixedFirstConfiguration::spcf_execute(std::shared_ptr<PSP> psp, shared_ptr<Solution> input)
{
    psp->UpdateSolution(input->GetConfiguration());
    return input;
}

string OM_FixedFirstConfiguration::codeToSend()
{
    return "A1";
}

string OM_FixedFirstConfiguration::TAG()
{
    return "Fixed_Start";
}
