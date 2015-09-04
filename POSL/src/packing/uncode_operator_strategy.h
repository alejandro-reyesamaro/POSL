#pragma once

#include "../operators/operator.h"
#include "uncode_cyclic_operator_strategy.h"
#include "uncode_conditional_operator_strategy.h"
#include "uncode_binary_operator_strategy.h"
#include "uncode_rho_operator_strategy.h"

class UncodeOperatorStrategy
{
    public:
        UncodeOperatorStrategy();
        Operator * uncode(string code, Benchmark * bench);

    private:
        UncodeCyclicOperatorStrategy * Cyc_strategy;
        UncodeConditionalOperatorStrategy * Con_strategy;
        UncodeRhoOperatorStrategy * Rho_strategy;
        UncodeBinaryOperatorStrategy * Bin_strategy;
};
