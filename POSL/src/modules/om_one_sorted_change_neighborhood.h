#pragma once

/**
 * POSL
 *
 * \file om_one_sorted_change_neighborhood.h
 * \brief Class to represent an Operation Module to generate a neighborhood of a given configuration (sorted)
 * \author Alejandro Reyes
 * \date 2015-08-12
 */

#include "aom_neighborhood_function.h"
#include "../data/solution.h"
#include "../benchmarks/benchmark.h"
#include "../data/neighborhood.h"
#include "../data/one_sorted_change_neighborhood.h"

/*!
 * \class OM_OneSortedChangeNeighborhood om_one_sorted_change_neighborhood.h
 * \brief Class to represent an Operation Module to generate a neighborhood of a given configuration (sorted)
 */
class OM_OneSortedChangeNeighborhood : public AOM_NeighborhoodFunction
{
    public:
        //! Constructor
        OM_OneSortedChangeNeighborhood(Benchmark * bench);

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
        OneSortedChangeNeighborhood * V;
};
