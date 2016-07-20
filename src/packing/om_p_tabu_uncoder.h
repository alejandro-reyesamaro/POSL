#pragma once

#include "../modules/om_tabu_configuration_set_processing.h"

class OM_P_Tabu_Uncoder
{
    public:
        OM_P_Tabu_Uncoder();
        std::shared_ptr<OM_TabuConfigurationSetProcessing> uncode(std::string code,
                                                                  std::shared_ptr<Benchmark>,
                                                                  shared_ptr<SearchProcessParamsStruct> psp_params);
};
