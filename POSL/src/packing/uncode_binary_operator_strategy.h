#pragma once

#include "../operators/binary_operator.h"

class UncodeBinaryOperatorStrategy
{
    public:
        UncodeBinaryOperatorStrategy();
        BinaryOperator * uncode(string code);
};
