#pragma once

/**
 * POSL
 *
 * \file om_always_improve_decition.h
 * \brief Class to represent an Operation Module to decide if a configuration is keeped to the next iteration
 * \author Alejandro Reyes
 * \date 2015-04-14
 */

#include "operation_module.h"

/*!
 * \class OM_AlwaysImproveDecition om_always_improve_decition.h
 * \brief Class to represent an Operation Module to decide if a configuration is keeped to the next iteration
 */
class OM_AlwaysImproveDecition : public OperationModule
{
    public:
        OM_AlwaysImproveDecition();

        //! Execute the O.M.
        /*!
        * \param psp The Problem Search Process
        * \param input Input (a desition pair)
        * \return The selected configuration
        */
        ComputationData * execute(PSP * psp, ComputationData * input);
};
