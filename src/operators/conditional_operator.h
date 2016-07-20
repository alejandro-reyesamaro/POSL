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
#include "../expressions/boolean_expression.h"

/*!
 * \class ConditionalOperator conditional_operator.h
 * \brief Class to represent the CONDITIONAL binary operator
 */
class ConditionalOperator : public BinaryOperator
{
    public:
        ConditionalOperator(std::shared_ptr<CompoundModule> _M1, std::shared_ptr<CompoundModule> _M2, std::shared_ptr<BooleanExpression> _ex);

        //! From Codable
        std::string codeToSend();

    private:
        std::shared_ptr<BooleanExpression> ex;
};
