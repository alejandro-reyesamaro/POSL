#pragma once

#include "../operators/operator.h"

class OperatorSendUncoder
{
    public:
        OperatorSendUncoder();
        std::shared_ptr<Operator> uncode(std::string code, std::shared_ptr<Benchmark> bench);
};
