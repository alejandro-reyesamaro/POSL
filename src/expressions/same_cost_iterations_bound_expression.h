#pragma once

#include "boolean_expression.h"

class SameCostIterationsBoundExpression : public BooleanExpression
{
    public:
        SameCostIterationsBoundExpression(int _max_iterations);
        bool evaluate(std::shared_ptr<PSP> psp);

        //! From Codable
        std::string codeToSend();

    private:
        int max_iter;
        int iterations;
        int cost;
        int current_cost;
};
