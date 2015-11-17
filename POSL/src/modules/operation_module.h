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
    std::vector<ConnectorInfo> Jacks() { return std::vector<ConnectorInfo>(0); }
    std::vector<ConnectorInfo> Outlets() { return std::vector<ConnectorInfo>(0); }
    void connect(ConnectorInfo, int) {}
};
