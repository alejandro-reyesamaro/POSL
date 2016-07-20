#include "aom_process_configuration.h"

std::shared_ptr<ComputationData> AOM_ProcessConfiguration::execute(std::shared_ptr<PSP> psp, std::shared_ptr<ComputationData> input)
{
    //psp->SearchingWithOuterInformation_OFF();
    return spcf_execute(psp, std::static_pointer_cast<Solution>(input));
}
