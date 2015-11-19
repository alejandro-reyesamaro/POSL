#include "aom_first_configuration_generation.h"

AOM_FirstConfigurationGeneration::AOM_FirstConfigurationGeneration(std::shared_ptr<Benchmark> bench)
    : domains(bench->Domains())
{}

std::shared_ptr<ComputationData> AOM_FirstConfigurationGeneration::execute(std::shared_ptr<PSP> psp, std::shared_ptr<ComputationData> input)
{
    return spcf_execute(psp, std::static_pointer_cast<Seed>(input));
}
