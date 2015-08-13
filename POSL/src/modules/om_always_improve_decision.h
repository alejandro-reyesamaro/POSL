#pragma once

/**
 * POSL
 *
 * \file om_always_improve_decision.h
 * \brief Class to represent an Operation Module to decide if a configuration is keeped to the next iteration
 * \author Alejandro Reyes
 * \date 2015-04-14
 */

#include "aom_decision_function.h"

/*!
 * \class OM_AlwaysImproveDecision om_always_improve_decision.h
 * \brief Class to represent an Operation Module to decide if a configuration is keeped to the next iteration
 */
class OM_AlwaysImproveDecision : public AOM_DecisionFunction
{
    public:
        OM_AlwaysImproveDecision();

        //! Execute the O.M.
        /*!
        * \param psp The Problem Search Process
        * \param input Input (a desition pair)
        * \return The selected configuration
        */
        Solution * spcf_execute(PSP * psp, DecisionPair * input);

        //! From Codable
        string codeToSend();
};
