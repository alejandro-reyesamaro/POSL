#pragma once

/**
 * POSL
 *
 * \file cyclic_operator.h
 * \brief Class to represent the CYCLIC unary operator
 * \author Alejandro Reyes
 * \date 2015-06-24
 */

#include "unary_operator.h"
#include "../expressions/boolean_expression.h"

/*!
 * \class CyclicOperator cyclic_operator.h
 * \brief Class to represent the CYCLIC unary operator
 */
class CyclicOperator : public UnaryOperator
{
    public:
        //! Contructor
        /*!
         * \param _M1 Module
         * \param ex Stop condition
         */
        CyclicOperator(CompoundModule * _M1, BooleanExpression * _ex);

        //! From Codable
        string codeToSend();

    private:
        BooleanExpression * ex;
};
