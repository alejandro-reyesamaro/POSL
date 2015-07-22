#pragma once

/**
 * POSL
 *
 * \file om_florian_random_conf_generation.h
 * \brief Class to represent an Operation module to generate a random first configuration (flo's idea)
 * \author Alejandro Reyes
 * \date 2015-04-14
 */

#include "operation_module.h"
#include "../data/solution.h"
#include "../benchmarks/benchmark.h"
#include "../data/seed.h"

/*!
 * \class OM_FlorianRandomConfGeneration om_florian_random_conf_generation.h
 * \brief Class to represent an Operation module to generate a random first configuration (flo's idea)
 */
class OM_FlorianRandomConfGeneration : public OperationModule
{
    public:
        OM_FlorianRandomConfGeneration();

        //! Execute the O.M.
        /*!
        * \brief The input is a configuration, but in this case is not tacken into account
        * \param psp The Problem Search Process
        * \param input Input (configuration)
        * \return A random configuration, but the best after certain iterations
        */
        ComputationData * execute(PSP * psp, ComputationData * input);
};
