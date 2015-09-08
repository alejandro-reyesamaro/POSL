#pragma once

/**
 * POSL
 *
 * \file operator.h
 * \brief Class to represent an operation between modules
 * \author Alejandro Reyes
 * \date 2015-05-12
 */

#include "../modules/compound_module.h"
#include "strategy/sequential_execution_strategy.h"
#include "strategy/parallel_execution_strategy.h"
#include "../packing/codable.h"

#include <vector>

using namespace std;

/*!
 * \class Operator operator.h
 * \brief Class to represent an operation between modules
 */
class Operator : public Codable
{
    public:
        Operator(shared_ptr<SequentialExecutionStrategy> _seq_strategy,
                 shared_ptr<ParallelExecutionStrategy> _para_strategy);

        shared_ptr<ComputationData> evaluateSequentially(shared_ptr<PSP> psp, shared_ptr<ComputationData> input);

        //! Method to evaluate the modules in parallel
        /*!
        * \param bench The Benchmark
        * \param input The operator input
        * \return The operator output
        */
        shared_ptr<ComputationData> evaluateInParallel(shared_ptr<PSP> psp, shared_ptr<ComputationData> input);

    protected:
        shared_ptr<SequentialExecutionStrategy> seq_strategy;
        shared_ptr<ParallelExecutionStrategy> para_strategy;
};
