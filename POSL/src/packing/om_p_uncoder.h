#pragma once

#include "../modules/operation_module.h"

class OM_P_Uncoder
{
    public:
        OM_P_Uncoder();
        std::shared_ptr<OperationModule> uncode(std::string code,
                                                std::shared_ptr<Benchmark> bench,
                                                shared_ptr<SearchProcessParamsStruct> psp_params);
};
