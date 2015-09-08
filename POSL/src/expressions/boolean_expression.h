#pragma once

#include "../packing/codable.h"
#include "../solver/psp.h"

class BooleanExpression : public Codable
{
    public:
        BooleanExpression();
        virtual bool evaluate(shared_ptr<PSP> psp) = 0;
};
