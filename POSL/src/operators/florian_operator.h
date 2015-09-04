#pragma once

/**
 * POSL
 *
 * \file florian_operator.h
 * \brief Class to represent the CYCLIC unary operator
 * \author Alejandro Reyes
 * \date 2015-08-27
 */

#include "unary_operator.h"
#include "../expressions/boolean_expression.h"

/*!
 * \class FlorianOperator florian_operator.h
 * \brief Class to represent the FLORIAN unary operator
 */
class FlorianOperator : public UnaryOperator
{
    public:
        //! Contructor
        /*!
         * \param _M1 Module
         */
        FlorianOperator(CompoundModule * _M1);

        //! From Codable
        string codeToSend();
};