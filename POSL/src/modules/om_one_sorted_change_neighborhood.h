#pragma once

/**
 * POSL
 *
 * \file om_one_sorted_change_neighborhood.h
 * \brief Class to represent an Operation Module to generate a neighborhood of a given configuration (sorted)
 * \author Alejandro Reyes
 * \date 2015-08-12
 */

#include "operation_module.h"
#include "../data/solution.h"
#include "../benchmarks/benchmark.h"
#include "../data/neighborhood.h"

/*!
 * \class OM_OneSortedChangeNeighborhood om_one_sorted_change_neighborhood.h
 * \brief Class to represent an Operation Module to generate a neighborhood of a given configuration (sorted)
 */
class OM_OneSortedChangeNeighborhood : public OperationModule
{
    public:
        //! Constructor
        OM_OneSortedChangeNeighborhood();

        //! Execute the O.M.
        /*!
        * \brief The input is a configuration
        * \param psp The Problem Search Process
        * \param input Input (configuration)
        * \return The Neighborhood of the input configuration
        */
        ComputationData * execute(PSP * psp, ComputationData * input);

        //! From Codable
        string codeToSend();
};
