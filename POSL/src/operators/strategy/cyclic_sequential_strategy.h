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
        CyclicSequentialStrategy(std::shared_ptr<CompoundModule> _M1, std::shared_ptr<BooleanExpression> _ex);

        std::shared_ptr<ComputationData> evaluate(std::shared_ptr<PSP> psp, std::shared_ptr<ComputationData> input);

    private:
        std::shared_ptr<CompoundModule> M1;
        std::shared_ptr<BooleanExpression> ex;

        std::shared_ptr<ComputationData> output;
};
