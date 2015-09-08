#pragma once

#include "boolean_expression.h"

class LoopBoundExpression : public BooleanExpression
{
    public:
        LoopBoundExpression(int _max_loops);
        bool evaluate(shared_ptr<PSP> psp);

        //! From Codable
        string codeToSend();

    private:
        int loop;
        int max_loops;
};
