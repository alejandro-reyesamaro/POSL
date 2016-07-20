#pragma once

#include "../modules/om_tabu_configuration_processing.h"

class OM_R_Tabu_Uncoder
{
    public:
        OM_R_Tabu_Uncoder();
        std::shared_ptr<OM_TabuConfigurationProcessing> uncode(std::string code,
                                                               std::shared_ptr<Benchmark>,
                                                               shared_ptr<SearchProcessParamsStruct> psp_params);
};
