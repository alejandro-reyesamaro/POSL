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
        CyclicOperator(std::shared_ptr<CompoundModule> _M1, std::shared_ptr<BooleanExpression> _ex);

        //! From Codable
        std::string codeToSend();

        //!From Connectable
        std::shared_ptr<HashMap<std::string, std::string>> GetConnections();
        void UpdateConnections(std::shared_ptr<HashMap<std::string, std::string>> connections_table);

    private:
        std::shared_ptr<BooleanExpression> ex;
};
