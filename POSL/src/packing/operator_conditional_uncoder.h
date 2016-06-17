#pragma once

#include "../operators/operator.h"

class OperatorConditionalUncoder
{
    public:
        OperatorConditionalUncoder();
        std::shared_ptr<Operator> uncode(std::string code,
                                         std::shared_ptr<Benchmark> bench,
                                         shared_ptr<SearchProcessParamsStruct> psp_params);
};
