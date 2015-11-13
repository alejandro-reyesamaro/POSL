#pragma once

/**
 * POSL
 *
 * \file operation_module.h
 * \brief Class to represent an Open Channel
 * \author Alejandro Reyes
 * \date 2015-04-14
 */

#include "compound_module.h"

/*!
 * \class OperationModule operation_module.h
 * \brief Class to represent an Open Channel
 */
class OperationModule : public CompoundModule
{
    //! From Connectable
    std::shared_ptr<HashMap<std::string, std::string>> GetConnections() { return nullptr; }
    void UpdateConnections(std::shared_ptr<HashMap<std::string, std::string>>) {}
};
