#pragma once

#include "../operators/conditional_operator.h"

class UncodeConditionalOperatorStrategy
{
    public:
        UncodeConditionalOperatorStrategy();
        ConditionalOperator * uncode(string code);
};
