#pragma once

#include "boolean_expression.h"

class ReachedCostExpression : public BooleanExpression
{
    public:
        ReachedCostExpression(int _cost);
        bool evaluate(PSP * psp);

    private:
        int cost;
};
