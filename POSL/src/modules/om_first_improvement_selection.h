#pragma once

/**
 * POSL
 *
 * \file om_first_improvement_selection.h
 * \brief Class to represent an Operation Module to select a configuration in a neighborhood
 * \author Alejandro Reyes
 * \date 2015-04-14
 */

#include "operation_module.h"

/*!
 * \class OM_FirstImprovementSelection om_first_improvement_selection.h
 * \brief Class to represent an Operation Module to select a configuration in a neighborhood
 */
class OM_FirstImprovementSelection : public OperationModule
{
    public:
        //! Constructor
        OM_FirstImprovementSelection();

        //! Execute the O.M.
        /*!
        * \param psp The Problem Search Process
        * \param input Input (a neighborhood)
        * \return The first configuration improuving the current cost
        */
        ComputationData * execute(PSP * psp, ComputationData * input);
};
