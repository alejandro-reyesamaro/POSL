#pragma once

/**
 * POSL
 *
 * \file sequential_execution_sequential_strategy.h
 * \brief Strategy of sequential computation for the operator Sequential Execution
 * \author Alejandro Reyes
 * \date 2015-05-28
 */

#include "sequential_computation_strategy.h"

/*!
 * \class SequentialExecutionSequentialStrategy sequential_execution_sequential_strategy.h
 * \brief Strategy of sequential computation for the operator Sequential Execution
 */
class SequentialExecutionSequentialStrategy : public SequentialComputationStrategy
{
    public:
        //! Constructor
        SequentialExecutionSequentialStrategy(CompoundModule * _M1, CompoundModule * _M2);

        //! (override) The result of evaluating a Compound Module (sequentially)
        /*!
        * \param bench A Benchmark
        * \param input The input of the Compound Module
        * \return <ps> Returns Execute( M2 ( Execute (M1) ) </pc>
        */
        ComputationData * evaluate(PSP * psp, ComputationData * input);

    private:
        //! Left Compund Module
        CompoundModule * M1;
        //! Right Compund Module
        CompoundModule * M2;
};
