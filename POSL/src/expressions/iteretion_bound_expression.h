#pragma once

#include "boolean_expression.h"

class IteretionBoundExpression : public BooleanExpression
{
    public:
        IteretionBoundExpression(int _max_iterations);
        bool evaluate(shared_ptr<PSP> psp);

        //! From Codable
        string codeToSend();

    private:
        int max_iterations;
};
