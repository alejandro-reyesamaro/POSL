#pragma once

/**
 * POSL
 *
 * \file conditional_operator.h
 * \brief Class to represent the CONDITIONAL binary operator
 * \author Alejandro Reyes
 * \date 2015-07-02
 */

#include "binary_operator.h"
#include "expressions/boolean_expression.h"

/*!
 * \class ConditionalOperator conditional_operator.h
 * \brief Class to represent the CONDITIONAL binary operator
 */
class ConditionalOperator : public BinaryOperator
{
    public:
        //! Contructor
        /*!
         * \param _M1 Module 1
         * \param _M2 Module 2
         * \param ex Stop condition
         */
        ConditionalOperator(CompoundModule * _M1, CompoundModule * _M2, BooleanExpression * ex);
};
