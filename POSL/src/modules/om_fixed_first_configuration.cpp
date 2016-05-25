#include "om_fixed_first_configuration.h"
#include "../tools/tokens_definition.h"

#include <random>
#include <iostream>

using namespace std;

OM_FixedFirstConfiguration::OM_FixedFirstConfiguration(shared_ptr<Benchmark> bench)
    : AOM_FirstConfigurationGeneration(bench)
{}

shared_ptr<Solution> OM_FixedFirstConfiguration::spcf_execute(shared_ptr<PSP> psp, shared_ptr<Seed>)
{
    //cout << Tag() << endl;
    shared_ptr<Solution> rsolution(make_shared<Solution>(psp->GetBenchmark()->Variable_Domain(),
                                                         psp->GetBenchmark()->GetDefaultConfiguration()));
    psp->Start(rsolution->get_conf_by_ref());
    return rsolution;
}

string OM_FixedFirstConfiguration::codeToSend()
{
    return OM_FIXED_FIRST_CONFIGURATION_TOK;
}

string OM_FixedFirstConfiguration::Tag()
{
    return "Fixed_Start";
}
