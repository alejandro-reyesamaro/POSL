#pragma once

#include "../modules/om_tabu_processing.h"

class OM_R_Tabu_Uncoder
{
    public:
        OM_R_Tabu_Uncoder();
        std::shared_ptr<OM_TabuProcessing> uncode(std::string code,
                                                  std::shared_ptr<Benchmark>,
                                                  shared_ptr<SearchProcessParamsStruct> psp_params);
};
