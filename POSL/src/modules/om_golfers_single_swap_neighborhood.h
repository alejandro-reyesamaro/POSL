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
        OM_GolfersSingleSwapNeighborhood(std::shared_ptr<Benchmark> bench);

        std::shared_ptr<Neighborhood> spcf_execute(std::shared_ptr<PSP> psp, std::shared_ptr<Solution> input);

        //! From Codable
        std::string codeToSend();

    private:
        std::shared_ptr<Golfers> object_bench;
        std::shared_ptr<GolfersSingleSwapNeighborhood> V;
};
