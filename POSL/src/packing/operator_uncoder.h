#pragma once

#include "../operators/operator.h"

class OperatorUncoder
{
    public:
        OperatorUncoder();
        std::shared_ptr<Operator> uncode(std::string code, std::shared_ptr<Benchmark> bench);
};
