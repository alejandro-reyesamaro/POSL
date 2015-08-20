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
        //! Constructor
        ConditionalSequentialStrategy(CompoundModule * _M1, CompoundModule * _M2, BooleanExpression * _ex);

        //! (override) The result of evaluating a Compound Module (Sequentially)
        /*!
        * \param bench A Benchmark
        * \param input The input of the Compound Module
        * \return <ps> Returns Execute( M1 ) if ex remains true, Execute( M2 ) othervise</pc>
        */
        ComputationData * evaluate(PSP * psp, ComputationData * input);

    private:
        //! The Module 1
        CompoundModule * M1;
        //! The Module 2
        CompoundModule * M2;
        //! The stop condition
        BooleanExpression * ex;
};
