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

        std::shared_ptr<ComputationData> execute(std::shared_ptr<PSP> psp, std::shared_ptr<ComputationData> input);

        //! From Codable
        std::string codeToSend();
};
