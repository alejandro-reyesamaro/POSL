#pragma once

/**
 * POSL
 *
 * \file speed_parallel_strategy.h
 * \brief Strategy of parallel computation for the operator SPEED
 * \author Alejandro Reyes
 * \date 2015-07-21
 */

#include "parallel_computation_strategy.h"

/*!
 * \class SpeedParallelStrategy speed_parallel_strategy.h
 * \brief Strategy of parallel computation for the operator SPEED
 */
class SpeedParallelStrategy : public ParallelComputationStrategy
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
        CompoundModule * M1;
        //! Right Compund Module
        CompoundModule * M2;
};
