#pragma once

/**
 * POSL
 *
 * \file om_one_element_changed_neighborhood.h
 * \brief Class to represent an Operation Module to generate a neighborhood of a given configuration
 * \author Alejandro Reyes
 * \date 2015-04-14
 */

#include "operation_module.h"
#include "../data/solution.h"
#include "../benchmarks/benchmark.h"
#include "../data/neighborhood.h"

/*!
 * \class OM_OneElementChangedNeighborhood om_one_element_changed_neighborhood.h
 * \brief Class to represent an Operation Module to generate a neighborhood of a given configuration
 */
class OM_OneElementChangedNeighborhood : public OperationModule
{
    public:
        //! Constructor
        OM_OneElementChangedNeighborhood();

        //! Execute the O.M.
        /*!
        * \brief The input is a configuration
        * \param psp The Problem Search Process
        * \param input Input (configuration)
        * \return The Neighborhood of the input configuration
        */
        ComputationData * execute(PSP * psp, ComputationData * input);

        //! From Packable
        int * pack();
};
