/**
 * POSL
 *
 * \file union_operator.h
 * \brief Class to represent the UNION operator
 * \author Alejandro Reyes
 * \date 2015-07-01
 */

#include "binary_operator.h"

/*!
 * \class UnionOperator union_operator.h
 * \brief Class to represent the UNION operator
 */
class UnionOperator : public BinaryOperator
{
    public:
        //! Contructor
        /*!
         * \param _M1 Module
         * \param _M2 Module
         */
        UnionOperator(CompoundModule * _M1, CompoundModule * _M2);
};
