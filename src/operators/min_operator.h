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
        MinOperator(std::shared_ptr<CompoundModule> _M1, std::shared_ptr<CompoundModule> _M2);

        //! From Codable
        std::string codeToSend();
};
