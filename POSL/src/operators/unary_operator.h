#pragma once

/**
 * POSL
 *
 * \file unary_operator.h
 * \brief Class to represent an operation with 1 module
 * \author Alejandro Reyes
 * \date 2015-06-23
 */

#include "operator.h"

/*!
 * \class UnaryOperator unary_operator.h
 * \brief Class to represent an operation with 1 module
 */
class UnaryOperator : public Operator
{
    public:
        UnaryOperator(shared_ptr<CompoundModule> _M1, shared_ptr<SequentialExecutionStrategy> seq_strgy);

    protected:
        shared_ptr<CompoundModule> M1;
};
