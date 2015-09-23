#pragma once

#include "boolean_expression.h"

class OrExpression : public BooleanExpression
{
    public:
        OrExpression(std::shared_ptr<BooleanExpression> _ex1, std::shared_ptr<BooleanExpression> _ex2);
        bool evaluate(std::shared_ptr<PSP> psp);

        //! From Codable
        std::string codeToSend();

    private:
        std::shared_ptr<BooleanExpression> ex1;
        std::shared_ptr<BooleanExpression> ex2;
};
