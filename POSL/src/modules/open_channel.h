#pragma once

/**
 * POSL
 *
 * \file open_channel.h
 * \brief Class to represent an Open Channel
 * \author Alejandro Reyes
 * \date 2015-04-14
 */

#include "compound_module.h"

#define TAGOCh "OCh"

/*!
 * \class OpenChannel open_channel.h
 * \brief Class to represent an Open Channel
 */
class OpenChannel : public CompoundModule
{
    public:
        OpenChannel(std::string _name);
        virtual std::string Tag(){ return TAGOCh; }

        //! From Connectable
        std::shared_ptr<HashMap<std::string, std::string>> GetConnections();
        void UpdateConnections(std::shared_ptr<HashMap<std::string, std::string>> connections_table);

    protected:
        std::string name;
        std::string conn_tag;
};

