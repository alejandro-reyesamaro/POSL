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
        SendDataOperator(std::string _name, std::shared_ptr<CompoundModule> _M1);

        //! From Codable
        std::string codeToSend();

        //!From Connectable
        std::shared_ptr<HashMap<std::string, std::string>> GetConnections();
        void UpdateConnections(std::shared_ptr<HashMap<std::string, std::string>> connections_table);

    private:
        std::string name;
        std::string conn_tag;
};
