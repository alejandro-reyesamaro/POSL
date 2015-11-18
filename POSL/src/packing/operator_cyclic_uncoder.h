#pragma once

#include "../operators/operator.h"

class OperatorCyclicUncoder
{
    public:
        OperatorCyclicUncoder();
        std::shared_ptr<Operator> uncode(std::string code, std::shared_ptr<Benchmark> bench);
};
