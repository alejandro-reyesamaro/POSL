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
        //! Constructor
        /*!
        * \param _M1 Compound module 1 (left)
        * \param _M2 Compound module 2 (right)
        * \param seq_strgy Strategy for the sequential evaluation
        * \param par_strgy Strategy for the parallel evaluation
        */
        BinaryOperator(shared_ptr<CompoundModule> _M1,
                       shared_ptr<CompoundModule> _M2,
                       shared_ptr<SequentialExecutionStrategy> seq_strgy,
                       shared_ptr<ParallelExecutionStrategy> par_strgy);

    protected:
        shared_ptr<CompoundModule> M1;
        shared_ptr<CompoundModule> M2;
};
