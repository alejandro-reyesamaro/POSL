#pragma once

#include "boolean_expression.h"

class IteretionBoundExpression : public BooleanExpression
{
    public:
        IteretionBoundExpression(int _max_iterations);
        bool evaluate(PSP *psp);
    private:
        int max_iterations;
};
