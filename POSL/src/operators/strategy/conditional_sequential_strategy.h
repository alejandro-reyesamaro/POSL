#pragma once

/**
 * POSL
 *
 * \file conditional_sequential_strategy.h
 * \brief Strategy of sequential computation for the operator Conditional
 * \author Alejandro Reyes
 * \date 2015-07-02
 */

#include "sequential_execution_strategy.h"
#include "../../expressions/iteretion_bound_expression.h"

/*!
 * \class ConditionalSequentialStrategy conditional_sequential_strategy.h
 * \brief Strategy of sequential computation for the operator Rho
 */
class ConditionalSequentialStrategy : public SequentialExecutionStrategy
{
    public:
        ConditionalSequentialStrategy(std::shared_ptr<CompoundModule> _M1, std::shared_ptr<CompoundModule> _M2, std::shared_ptr<BooleanExpression> _ex);

        std::shared_ptr<ComputationData> evaluate(std::shared_ptr<PSP> psp, std::shared_ptr<ComputationData> input);

    private:
        std::shared_ptr<CompoundModule> M1;
        std::shared_ptr<CompoundModule> M2;
        std::shared_ptr<BooleanExpression> ex;

        std::shared_ptr<ComputationData> output1;
        std::shared_ptr<ComputationData> output2;
};
