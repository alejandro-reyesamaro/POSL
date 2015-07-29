#pragma once

/**
 * POSL
 *
 * \file oms_time_counter.h
 * \brief Class to represent a Spesial Operation Module to measure the time
 * \author Alejandro Reyes
 * \date 2015-07-28
 */

#include "operation_module.h"
#include "../tools/chronometer.h"

/*!
 * \class OMS_TimeCounter oms_time_counter.h
 * \brief Class to represent a Spesial Operation Module to measure the time
 */
class OMS_TimeCounter : public OperationModule
{
    public:
        OMS_TimeCounter();

        //! Execute the O.M.
        /*!
        * \param psp The Problem Search Process
        * \param input Input (a neighborhood)
        * \return A random configuration, improving or not the cost
        */
        ComputationData * execute(PSP * psp, ComputationData * input);

        //! From Codable
        string codeToSend();

    private:
        Chronometer * chrono;
};
