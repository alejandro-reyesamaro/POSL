#pragma once

#include "../expressions/boolean_expression.h"

class UncodeBoolExpressionStrategy
{
    public:
        UncodeBoolExpressionStrategy();
        BooleanExpression * uncode(string code);
};
