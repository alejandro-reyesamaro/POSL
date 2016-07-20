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
        SequentialExecOperator(std::shared_ptr<CompoundModule> _M1, std::shared_ptr<CompoundModule> _M2);

        //! From Codable
        std::string codeToSend();
};
