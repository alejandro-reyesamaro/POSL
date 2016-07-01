#include "aom_first_configuration_generation_from_set.h"

AOM_FirstConfigurationGenerationFromSet::AOM_FirstConfigurationGenerationFromSet(std::shared_ptr<Benchmark> bench)
    : domain(bench->Variable_Domain())
{}

std::shared_ptr<ComputationData> AOM_FirstConfigurationGenerationFromSet::execute(std::shared_ptr<PSP> psp, std::shared_ptr<ComputationData> input)
{
    psp->StartSearch();
    return spcf_execute(psp, std::static_pointer_cast<ConfigurationSet>(input));
}
