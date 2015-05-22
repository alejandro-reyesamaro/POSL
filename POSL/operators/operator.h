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
 * \class Operation operator.h
 * \brief Class to represent an operation between modules
 */
class Operator
{
    public:
        Operator(SequentialComputationStrategy * _seq_strategy,
                 ParallelComputationStrategy * _para_strategy);

        virtual ComputationData * evaluateSequentially(Benchmark * bench, ComputationData * input) = 0;
        virtual ComputationData * evaluateInParallel(Benchmark * bench, ComputationData * input) = 0;

    protected:
        SequentialComputationStrategy * seq_strategy;
        ParallelComputationStrategy * para_strategy;
};
