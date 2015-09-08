#pragma once

#include "boolean_expression.h"

class ReachedCostExpression : public BooleanExpression
{
    public:
        ReachedCostExpression(int _cost);
        bool evaluate(shared_ptr<PSP> psp);

        //! From Codable
        string codeToSend();

    private:
        int cost;
};
