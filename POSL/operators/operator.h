#pragma once

/**
 * POSL
 *
 * \file operator.h
 * \brief Class to represent an operation between modules
 * \author Alejandro Reyes
 * \date 2015-05-12
 */

#include "modules/compound_module.h"
#include "computation/sequential_computation_strategy.h"
#include "computation/parallel_computation_strategy.h"

#include <vector>

using namespace std;

/*!
 * \class Operator operator.h
 * \brief Class to represent an operation between modules
 */
class Operator
{
    public:
        //! Constructor
        /*!
        * \param _seq_strgy Strategy for the sequential evaluation
        * \param _par_strgy Strategy for the parallel evaluation
        */
        Operator(SequentialComputationStrategy * _seq_strategy,
                 ParallelComputationStrategy * _para_strategy);

        //! Method to evaluate the modules sequentially
        /*!
        * \param bench The Benchmark
        * \param input The operator input
        * \return The operator output
        */
        ComputationData * evaluateSequentially(PSP * psp, ComputationData * input);

        //! Method to evaluate the modules in parallel
        /*!
        * \param bench The Benchmark
        * \param input The operator input
        * \return The operator output
        */
        ComputationData * evaluateInParallel(PSP * psp, ComputationData * input);

    protected:
        //! Sequential computation strategy
        SequentialComputationStrategy * seq_strategy;
        //! Parallel computation strategy
        ParallelComputationStrategy * para_strategy;
};
