#pragma once

#include "../operators/operator.h"

class OperatorFloUncoder
{
    public:
        OperatorFloUncoder();
        std::shared_ptr<Operator> uncode(std::string code, std::shared_ptr<Benchmark> bench);
};
