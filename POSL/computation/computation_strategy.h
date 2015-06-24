#pragma once

/**
 * POSL
 *
 * \file computation_trategy.h
 * \brief (Abstract) Class to represent a strategy of computation (sequential or in parallel)
 * \author Alejandro Reyes
 * \date 2015-05-28
 */

#include "data/computation_data.h"
#include "benchmarks/benchmark.h"
#include "modules/compound_module.h"

/*!
 * \class ComputationStrategy computation_strategy.h
 * \brief (Abstract) Class to represent a strategy of computation (sequential or in parallel)
 */
class ComputationStrategy
{
    public:
        //! The result of evaluating a Compound Module
        /*!
        * \param bench A Benchmark
        * \param input The input of the Compound Module
        * \return The output of the Compound Module
        */
        virtual ComputationData * evaluate(PSP * psp, ComputationData * input) = 0;
};
