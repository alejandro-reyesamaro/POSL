#pragma once

/**
 * POSL
 *
 * \file om_random_conf_generation.h
 * \brief Class to represent an Operation module to generate a random first configuration
 * \author Alejandro Reyes
 * \date 2015-04-14
 */

#include "operation_module.h"
#include "../data/solution.h"
#include "../benchmarks/benchmark.h"
#include "../data/seed.h"

/*!
 * \class OM_RandomConfGeneration om_random_conf_generation.h
 * \brief Class to represent an Operation module to generate a random first configuration
 */
class OM_RandomConfGeneration : public OperationModule
{
    public:
        //! Constructor
        OM_RandomConfGeneration();

        //! Execute the O.M.
        /*!
        * \brief The input is a configuration, but in this case is not tacken into account
        * \param psp The Problem Search Process
        * \param input Input (configuration)
        * \return A random configuration
        */
        ComputationData * execute(PSP * psp, ComputationData * input);

        //! From Codable
        string codeToSend();
};
