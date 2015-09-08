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
        OM_OneSortedChangeNeighborhood(shared_ptr<Benchmark> bench);

        shared_ptr<Neighborhood> spcf_execute(shared_ptr<PSP> psp, shared_ptr<Solution> input);

        //! From Codable
        string codeToSend();

    private:
        shared_ptr<OneSortedChangeNeighborhood> V;
};
