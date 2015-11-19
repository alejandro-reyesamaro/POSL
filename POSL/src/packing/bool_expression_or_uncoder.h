#pragma once

#include "../expressions/boolean_expression.h"

class BoolExpressionOrUncoder
{
    public:
        BoolExpressionOrUncoder();
        std::shared_ptr<BooleanExpression> uncode(std::string code);
};
