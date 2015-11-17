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
        FlorianOperator(std::shared_ptr<CompoundModule> _M1);

        //! From Codable
        std::string codeToSend();

        //!From Connectable
        std::vector<ConnectorInfo> Jacks();
        std::vector<ConnectorInfo> Outlets();
        void connect(ConnectorInfo connector, int procID);
};
