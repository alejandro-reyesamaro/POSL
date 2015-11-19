#pragma once

#include "boolean_expression.h"

#define BE_REACHED_COST_TOK "BE.RC"

class ReachedCostExpression : public BooleanExpression
{
    public:
        ReachedCostExpression(int _cost);
        bool evaluate(std::shared_ptr<PSP> psp);

        //! From Codable
        std::string codeToSend();

    private:
        int cost;
};
