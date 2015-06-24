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
        //! Constructor
        /*!
        * \brief No parallel strategy will be implemented
        * \param _M1 The compound module
        * \param seq_strgy Strategy for the sequential evaluation
        */
        UnaryOperator(CompoundModule * _M1, SequentialComputationStrategy * seq_strgy);

    protected:
        //! The compound module
        CompoundModule * M1;
};
