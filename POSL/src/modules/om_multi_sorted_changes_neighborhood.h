#pragma once

/**
 * POSL
 *
 * \file om_multi_sorted_changes_neighborhood.h
 * \brief Class to represent an Operation Module to generate a neighborhood of a given configuration
 * \author Alejandro Reyes
 * \date 2015-08-10
 */

#include "aom_neighborhood_function.h"
#include "../data/solution.h"
#include "../benchmarks/benchmark.h"
#include "../data/neighborhood.h"
#include "../data/multi_sorted_changes_neighborhood.h"

/*!
 * \class OM_MultiSortedChangesNeighborhood om_multi_sorted_changes_neighborhood.h
 * \brief Class to represent an Operation Module to generate a neighborhood of a given configuration
 */
class OM_MultiSortedChangesNeighborhood : public AOM_NeighborhoodFunction
{
    public:
        //! Constructor
        OM_MultiSortedChangesNeighborhood(Benchmark * bench);

        //! Execute the O.M.
        /*!
        * \brief The input is a configuration
        * \param psp The Problem Search Process
        * \param input Input (configuration)
        * \return The Neighborhood of the input configuration
        */
        Neighborhood * spcf_execute(PSP * psp, Solution * input);

        //! From Codable
        string codeToSend();

    private:
        MultiSortedChangesNeighborhood * V;
};
