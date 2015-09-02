#pragma once

#include "../operators/rho_operator.h"

class UncodeRhoOperatorStrategy
{
    public:
        UncodeRhoOperatorStrategy();
        RhoOperator * uncode(string code, Benchmark * bench);
};
