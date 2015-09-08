#include "aom_first_configuration_generation.h"

AOM_FirstConfigurationGeneration::AOM_FirstConfigurationGeneration(shared_ptr<Benchmark> bench)
    : domains(bench->Domains())
{}

shared_ptr<ComputationData> AOM_FirstConfigurationGeneration::execute(shared_ptr<PSP> psp, shared_ptr<ComputationData> input)
{
    return spcf_execute(psp, static_pointer_cast<Solution>(input));
}
