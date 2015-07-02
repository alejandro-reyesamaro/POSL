#pragma once

/**
 * POSL
 *
 * \file om_simulated_annealing_decition.h
 * \brief Class to represent an Operation Module to decide if a configuration is keeped to the next iteration
 * \author Alejandro Reyes
 * \date 2015-07-02
 */

#include "operation_module.h"

/*!
 * \class OM_SimulatedAnnealingDecition om_simulated_annealing_decition.h
 * \brief Class to represent an Operation Module to decide if a configuration is keeped to the next iteration
 */
class OM_SimulatedAnnealingDecition : public OperationModule
{
    public:
        OM_SimulatedAnnealingDecition();

        //! Execute the O.M.
        /*!
        * \param psp The Problem Search Process
        * \param input Input (a desition pair)
        * \return The selected configuration
        */
        ComputationData * execute(PSP * psp, ComputationData * input);
};
