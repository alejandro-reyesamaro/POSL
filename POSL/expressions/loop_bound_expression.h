#pragma once

#include "boolean_expression.h"

class LoopBoundExpression : public BooleanExpression
{
    public:
        LoopBoundExpression(int _max_loops);
        bool evaluate(PSP * psp);

    private:
        int loop;
        int max_loops;
};
