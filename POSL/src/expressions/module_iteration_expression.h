#pragma once

#include "boolean_expression.h"

class ModuleIterationExpression : public BooleanExpression
{
    public:
        ModuleIterationExpression(int _iterations);
        bool evaluate(std::shared_ptr<PSP> psp);

        //! From Codable
        std::string codeToSend();

    private:
        int iterations;
};
