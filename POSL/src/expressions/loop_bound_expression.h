#pragma once

#include "boolean_expression.h"

#define BE_LOOP_BOUND_TOK "BE.LoopBnd"

class LoopBoundExpression : public BooleanExpression
{
    public:
        LoopBoundExpression(int _max_loops);
        bool evaluate(std::shared_ptr<PSP> psp);

        //! From Codable
        std::string codeToSend();

    private:
        int loop;
        int max_loops;
};
