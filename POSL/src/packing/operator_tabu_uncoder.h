#pragma once

#include "../operators/operator.h"

class OperatorTabuUncoder
{
    public:
        OperatorTabuUncoder();
        std::shared_ptr<Operator> uncode(std::string code, std::shared_ptr<Benchmark> bench);
};
