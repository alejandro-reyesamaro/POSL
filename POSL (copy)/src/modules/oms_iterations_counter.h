#pragma once

/**
 * POSL
 *
 * \file oms_iterations_counter.h
 * \brief Class to represent a Spesial Operation Module to count the number of iterations
 * \author Alejandro Reyes
 * \date 2015-07-28
 */

#include "operation_module.h"

/*!
 * \class OMS_IterationsCounter oms_iterations_counter.h
 * \brief Class to represent a Spesial Operation Module to count the number of iterations
 */
class OMS_IterationsCounter : public OperationModule
{
    public:
        OMS_IterationsCounter();

        //! Execute the O.M.
        /*!
        * \param psp The Problem Search Process
        * \param input Input (a neighborhood)
        * \return A random configuration, improving or not the cost
        */
        ComputationData * execute(PSP * psp, ComputationData * input);

        //! From Codable
        string codeToSend();
};
