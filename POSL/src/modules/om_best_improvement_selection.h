#pragma once

/**
 * POSL
 *
 * \file om_best_improvement_selection.h
 * \brief Class to represent an Operation Module to select a configuration in a neighborhood
 * \author Alejandro Reyes
 * \date 2015-04-14
 */

#include "operation_module.h"

/*!
 * \class OM_BestImprovementSelection om_best_improvement_selection.h
 * \brief Class to represent an Operation Module to select a configuration in a neighborhood
 */
class OM_BestImprovementSelection : public OperationModule
{
    public:
        OM_BestImprovementSelection();

        //! Execute the O.M.
        /*!
        * \param psp The Problem Search Process
        * \param input Input (a neighborhood)
        * \return The configuration that improuves the best the current cost
        */
        ComputationData * execute(PSP * psp, ComputationData * input);

        //! From Codable
        string codeToSend();
};
