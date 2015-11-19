#include "om_fixed_first_configuration.h"

#include <random>
#include <iostream>

using namespace std;

OM_FixedFirstConfiguration::OM_FixedFirstConfiguration(shared_ptr<Benchmark> bench)
    : AOM_FirstConfigurationGeneration(bench)
{}

shared_ptr<Solution> OM_FixedFirstConfiguration::spcf_execute(std::shared_ptr<PSP> psp, std::shared_ptr<Seed>)
{
    //psp->UpdateSolution(config);
    return make_shared<Solution>(psp->GetBenchmark()->Domains(), psp->GetCurrentSolution());
}

string OM_FixedFirstConfiguration::codeToSend()
{
    return OM_FIXED_FIRST_CONFIGURATION_TOK;
}

string OM_FixedFirstConfiguration::Tag()
{
    return "Fixed_Start";
}
