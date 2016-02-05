#include "aom_rearrange_configuration.h"

std::shared_ptr<ComputationData> AOM_RearrangeConfiguration::execute(std::shared_ptr<PSP> psp, std::shared_ptr<ComputationData> input)
{
    //psp->SearchingWithOuterInformation_OFF();
    return spcf_execute(psp, std::static_pointer_cast<Solution>(input));
}
