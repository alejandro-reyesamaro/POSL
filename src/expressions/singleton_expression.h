#pragma once

#include "boolean_expression.h"

class SingletonExpression : public BooleanExpression
{
    public:
        SingletonExpression();
        bool evaluate(std::shared_ptr<PSP>);

        //! From Codable
        std::string codeToSend();

    private:
        bool executed;
};
