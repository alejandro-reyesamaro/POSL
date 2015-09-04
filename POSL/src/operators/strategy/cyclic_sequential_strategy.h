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
        CyclicSequentialStrategy(CompoundModule * _M1, BooleanExpression * _ex);

        //! (override) The result of evaluating a Compound Module (Sequentially)
        /*!
        * \param bench A Benchmark
        * \param input The input of the Compound Module
        * \return <ps> Returns Execute( M1 ) while (ex remains true) </pc>
        */
        ComputationData * evaluate(PSP * psp, ComputationData * input);

    private:
        CompoundModule * M1;
        BooleanExpression * ex;

        ComputationData * output;
};
