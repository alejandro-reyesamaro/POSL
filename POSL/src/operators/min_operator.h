#pragma once

/**
 * POSL
 *
 * \file min_operator.h
 * \brief Class to represent the MIN binary operator
 * \author Alejandro Reyes
 * \date 2015-08-20
 */

#include "binary_operator.h"

/*!
 * \class MinOperator min_operator.h
 * \brief Class to represent the MIN operator
 */
class MinOperator : public BinaryOperator
{
    public:
        //! Contructor
        /*!
         * \param _M1 Module
         * \param _M2 Module
         */
        MinOperator(CompoundModule * _M1, CompoundModule * _M2);

        //! From Codable
        string codeToSend();
};
