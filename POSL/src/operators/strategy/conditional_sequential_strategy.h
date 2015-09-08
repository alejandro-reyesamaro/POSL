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
        ConditionalSequentialStrategy(shared_ptr<CompoundModule> _M1, shared_ptr<CompoundModule> _M2, shared_ptr<BooleanExpression> _ex);

        shared_ptr<ComputationData> evaluate(shared_ptr<PSP> psp, shared_ptr<ComputationData> input);

    private:
        shared_ptr<CompoundModule> M1;
        shared_ptr<CompoundModule> M2;
        shared_ptr<BooleanExpression> ex;

        shared_ptr<ComputationData> output1;
        shared_ptr<ComputationData> output2;
};
