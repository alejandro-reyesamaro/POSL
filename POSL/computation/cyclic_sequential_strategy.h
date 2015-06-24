#pragma once

/**
 * POSL
 *
 * \file rho_sequential_strategy.h
 * \brief Strategy of sequential computation for the operator Rho
 * \author Alejandro Reyes
 * \date 2015-06-23
 */

#include "sequential_computation_strategy.h"
#include "expressions/iteretion_bound_expression.h"

/*!
 * \class RhoSequentialStrategy rho_sequential_strategy.h
 * \brief Strategy of sequential computation for the operator Rho
 */
class CyclicSequentialStrategy : public SequentialComputationStrategy
{
    public:
        //! Constructor
        CyclicSequentialStrategy(CompoundModule * _M1, IteretionBoundExpression * _ex);

        //! (override) The result of evaluating a Compound Module (in parallel)
        /*!
        * \param bench A Benchmark
        * \param input The input of the Compound Module
        * \return <ps> Returns Execute( M1 ) while (ex remains true) </pc>
        */
        ComputationData * evaluate(PSP * psp, ComputationData * input);

    private:
        //! The Module
        CompoundModule * M1;
        //! The stop condition
        IteretionBoundExpression * ex;
};
