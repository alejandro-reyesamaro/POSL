#pragma once

#include "../operators/conditional_operator.h"
#include "uncode_compound_module_strategy.h"
#include "uncode_bool_expression_strategy.h"

class UncodeConditionalOperatorStrategy
{
    public:
        UncodeConditionalOperatorStrategy();
        ConditionalOperator * uncode(string code, Benchmark * bench);

    private:
        UncodeCompoundModuleStrategy * CM_strategy;
        UncodeBoolExpressionStrategy * BE_strategy;
};
