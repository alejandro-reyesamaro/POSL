#pragma once

#include "../operators/operator.h"

class UncodeOperatorStrategy
{
    public:
        UncodeOperatorStrategy();
        Operator * uncode(string code, Benchmark * bench);
};
