#pragma once

#include "../expressions/boolean_expression.h"

class BooleanExpressionUncoder
{
    public:
        BooleanExpressionUncoder();
        std::shared_ptr<BooleanExpression> uncode(std::string code);
};
