#pragma once

#include "../expressions/boolean_expression.h"

class BoolExpressionAndUncoder
{
    public:
        BoolExpressionAndUncoder();
        std::shared_ptr<BooleanExpression> uncode(std::string code);
};
