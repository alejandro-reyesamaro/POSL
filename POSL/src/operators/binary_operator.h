#pragma once

/**
 * POSL
 *
 * \file binary_operator.h
 * \brief Class to represent an operation between 2 modules
 * \author Alejandro Reyes
 * \date 2015-06-23
 */

#include "operator.h"

/*!
 * \class BinaryOperator binary_operator.h
 * \brief Class to represent an operation between 2 modules
 */
class BinaryOperator : public Operator
{
    public:
        BinaryOperator(std::shared_ptr<CompoundModule> _M1,
                       std::shared_ptr<CompoundModule> _M2,
                       std::shared_ptr<SequentialExecutionStrategy> seq_strgy,
                       std::shared_ptr<ParallelExecutionStrategy> par_strgy);

    protected:
        std::shared_ptr<CompoundModule> M1;
        std::shared_ptr<CompoundModule> M2;
};
