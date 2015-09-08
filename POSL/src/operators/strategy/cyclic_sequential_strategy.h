#pragma once

/**
 * POSL
 *
 * \file cyclic_sequential_strategy.h
 * \brief Strategy of sequential computation for the operator Cyclic
 * \author Alejandro Reyes
 * \date 2015-06-23
 */

#include "sequential_execution_strategy.h"
#include "../../expressions/iteretion_bound_expression.h"

/*!
 * \class CyclicSequentialStrategy cyclic_sequential_strategy.h
 * \brief Strategy of sequential computation for the operator Cyclic
 */
class CyclicSequentialStrategy : public SequentialExecutionStrategy
{
    public:
        CyclicSequentialStrategy(shared_ptr<CompoundModule> _M1, shared_ptr<BooleanExpression> _ex);

        shared_ptr<ComputationData> evaluate(shared_ptr<PSP> psp, shared_ptr<ComputationData> input);

    private:
        shared_ptr<CompoundModule> M1;
        shared_ptr<BooleanExpression> ex;

        shared_ptr<ComputationData> output;
};
