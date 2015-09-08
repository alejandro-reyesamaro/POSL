#pragma once

/**
 * POSL
 *
 * \file execution_trategy.h
 * \brief (Abstract) Class to represent a strategy of execution (sequential or in parallel)
 * \author Alejandro Reyes
 * \date 2015-05-28
 */

#include "../../data/computation_data.h"
#include "../../benchmarks/benchmark.h"
#include "../../modules/compound_module.h"

/*!
 * \class ExecutionStrategy execution_strategy.h
 * \brief (Abstract) Class to represent a strategy of execution (sequential or in parallel)
 */
class ExecutionStrategy
{
    public:
        virtual shared_ptr<ComputationData> evaluate(shared_ptr<PSP> psp, shared_ptr<ComputationData> input) = 0;
};
