#pragma once

/**
 * POSL
 *
 * \file sequential_exec_operator.h
 * \brief Class to represent the SEQUENTIAL EXECUTION binary operator
 * \author Alejandro Reyes
 * \date 2015-06-23
 */

#include "binary_operator.h"

/*!
 * \class SequentialExecOperator sequential_exec_operator.h
 * \brief Class to represent the SEQUENTIAL EXECUTION binary operator
 */
class SequentialExecOperator : public BinaryOperator
{
    public:
        //! Contructor
        /*!
         * \param _M1 Module
         * \param _M2 Module
         */
        SequentialExecOperator(CompoundModule * _M1, CompoundModule * _M2);
};
