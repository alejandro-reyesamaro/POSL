#pragma once

#include "solver/psp.h"

class BooleanExpression
{
    public:
        BooleanExpression();
        virtual bool evaluate(PSP *psp) = 0;
};
