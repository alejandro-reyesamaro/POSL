#pragma once

/**
 * POSL
 *
 * \file om_golfers_single_swap_neighborhood.h
 * \brief Class to represent an Operation Module to generate a neighborhood of a given configuration (for golfers problem)
 * \author Alejandro Reyes
 * \date 2015-07-07
 */

#include "aom_neighborhood_function.h"
#include "../data/solution.h"
#include "../benchmarks/benchmark.h"
#include "../data/neighborhood.h"
#include "../benchmarks/golfers.h"
#include "../data/golfers_single_swap_neighborhood.h"

/*!
 * \class OM_GolfersSingleSwapNeighborhood om_golfers_single_swap_neighborhood.h
 * \brief Class to represent an Operation Module to generate a neighborhood of a given configuration (for golfers problem)
 */
class OM_GolfersSingleSwapNeighborhood : public AOM_NeighborhoodFunction
{
    public:
        //! Constructor
        OM_GolfersSingleSwapNeighborhood(Benchmark *bench);

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
        Golfers * object_bench;
        GolfersSingleSwapNeighborhood * V;
};
