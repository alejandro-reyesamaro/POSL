#pragma once

#include "../packing/codable.h"

#include "../solver/psp.h"

class BooleanExpression : public Codable
{
    public:
        BooleanExpression();
        virtual bool evaluate(PSP *psp) = 0;
};
