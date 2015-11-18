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
#include "strategy/florian_sequential_strategy.h"

/*!
 * \class FlorianOperator florian_operator.h
 * \brief Class to represent the FLORIAN unary operator
 */
class FlorianOperator : public UnaryOperator
{
    public:
        FlorianOperator(int k, std::shared_ptr<CompoundModule> _M1);

        //! From Codable
        std::string codeToSend();

        //!From Connectable
        std::vector<ConnectorInfo> Jacks();
        std::vector<ConnectorInfo> Outlets();
        void connect(ConnectorInfo connector, int procID);

    private:
        std::shared_ptr<FlorianSequentialStrategy> CastMyStrategy();
};
