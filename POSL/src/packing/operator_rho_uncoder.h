#pragma once

#include "../operators/operator.h"

class OperatorRhoUncoder
{
    public:
        OperatorRhoUncoder();
        std::shared_ptr<Operator> uncode(std::string code, std::shared_ptr<Benchmark> bench);
};
