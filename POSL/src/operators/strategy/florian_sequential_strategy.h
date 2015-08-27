#pragma once

/**
 * POSL
 *
 * \file florian_sequential_strategy.h
 * \brief Strategy of sequential computation for the operator FLORIAN
 * \author Alejandro Reyes
 * \date 2015-08-27
 */

#include "sequential_execution_strategy.h"

/*!
 * \class FlorianSequentialStrategy florian_sequential_strategy.h
 * \brief Strategy of sequential computation for the operator FLORIAN
 */
class FlorianSequentialStrategy : public SequentialExecutionStrategy
{
    public:
        //! Constructor
        FlorianSequentialStrategy(CompoundModule * _M1);

        //! (override) The result of evaluating a Compound Module (Sequentially)
        /*!
        * \param bench A Benchmark
        * \param input The input of the Compound Module
        * \return returns the best Execute( M1 )
        */
        ComputationData * evaluate(PSP * psp, ComputationData * input);

    private:
        //! The Module
        CompoundModule * M1;
};
