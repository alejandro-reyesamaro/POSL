#pragma once

/**
 * POSL
 *
 * \file not_implemented_parallel_strategy.h
 * \brief Class to represent a not supported strategy (in parallel)
 * \author Alejandro Reyes
 * \date 2015-05-28
 */

#include "parallel_computation_strategy.h"

/*!
 * \class NotImplementedParallelStrategy not_implemented_parallel_strategy.h
 * \brief Class to represent a not supported strategy (in parallel)
 */
class NotImplementedParallelStrategy : public ParallelComputationStrategy
{
    public:
        //! Constructor
        NotImplementedParallelStrategy();

        //! (override) The result of evaluating a Compound Module (in parallel)
        /*!
        * \param bench A Benchmark
        * \param input The input of the Compound Module
        * \return Throws an exception
        */
        ComputationData * evaluate(PSP *psp, ComputationData * input);
};
