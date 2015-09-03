#pragma once

/**
 * POSL
 *
 * \file om_one_permutation_neighborhood.h
 * \brief Class to represent an Operation Module to generate a neighborhood of a given configuration
 * \author Alejandro Reyes
 * \date 2015-08-31
 */

#include "aom_neighborhood_function.h"
#include "../data/solution.h"
#include "../benchmarks/benchmark.h"
#include "../data/neighborhood.h"
#include "../data/one_permutation_neighborhood.h"

/*!
 * \class OM_OnePermutationNeighborhood om_one_permutation_neighborhood.h
 * \brief Class to represent an Operation Module to generate a neighborhood of a given configuration
 */
class OM_OnePermutationNeighborhood : public AOM_NeighborhoodFunction
{
    public:
        //! Constructor
        OM_OnePermutationNeighborhood(Benchmark * bench);

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
        OnePermutationNeighborhood * V;
};
