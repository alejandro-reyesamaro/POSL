#pragma once

/**
 * POSL
 *
 * \file speed_parallel_strategy.h
 * \brief Strategy of parallel computation for the operator SPEED
 * \author Alejandro Reyes
 * \date 2015-07-21
 */

#include "parallel_execution_strategy.h"
#include "executer.h"

/*!
 * \class SpeedParallelStrategy speed_parallel_strategy.h
 * \brief Strategy of parallel computation for the operator SPEED
 */
class SpeedParallelStrategy : public ParallelExecutionStrategy
{
    public:
        //! Constructor
        SpeedParallelStrategy(CompoundModule * _M1, CompoundModule * _M2);

        //! (override) The result of evaluating a Compound Module (parallel)
        /*!
        * \param bench A Benchmark
        * \param input The input of the Compound Module
        * \return The fastest module
        */
        ComputationData * evaluate(PSP * psp, ComputationData * input);

    private:
        //! Left Compund Module
        Executer M1;
        //! Right Compund Module
        Executer M2;
};