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

        shared_ptr<ComputationData> execute(shared_ptr<PSP> psp, shared_ptr<ComputationData> input);

        //! From Codable
        string codeToSend();

        std::string TAG();

    protected:
        shared_ptr<Chronometer> chrono;
};
