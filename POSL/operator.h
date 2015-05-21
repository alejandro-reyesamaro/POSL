#pragma once

/**
 * POSL
 *
 * \file operator.h
 * \brief Class to represent an operation between modules
 * \author Alejandro Reyes
 * \date 2015-05-12
 */

#include "compound_module.h"
#include "sequential_computation_strategy.h"
#include "parallelc_omputation_strategy.h"

#include <vector>
#include <memory>

using namespace std;

/*!
 * \class Operation operator.h
 * \brief Class to represent an operation between modules
 */
class Operator
{
    public:
        Operator(shared_ptr<ComputationStrategy> _seq_strategy,
                 shared_ptr<ComputationStrategy> _para_strategy);

        virtual void evaluate() = 0;

    private:
        shared_ptr<ComputationStrategy> seq_strategy;
        shared_ptr<ComputationStrategy> para_strategy;
};
