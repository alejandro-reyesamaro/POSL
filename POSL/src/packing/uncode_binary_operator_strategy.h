#pragma once

#include "../operators/binary_operator.h"
#include "uncode_compound_module_strategy.h"

class UncodeBinaryOperatorStrategy
{
    public:
        UncodeBinaryOperatorStrategy();
        BinaryOperator * uncode(string code, Benchmark * bench);

    private:
        UncodeCompoundModuleStrategy * cm_strategy;
};
