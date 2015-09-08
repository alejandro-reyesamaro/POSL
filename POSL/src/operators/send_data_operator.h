#pragma once

/**
 * POSL
 *
 * \file send_data_operator.h
 * \brief Class to represent an operator to send data to others solvers
 * \author Alejandro Reyes
 * \date 2015-08-19
 */

#include "unary_operator.h"

/*!
 * \class SendDataOperator send_data_operator.h
 * \brief Class to represent an operator to send data to others solvers
 */
class SendDataOperator : public UnaryOperator
{
    public:
        SendDataOperator(shared_ptr<CompoundModule> _M1);

        //! From Codable
        string codeToSend();
};
