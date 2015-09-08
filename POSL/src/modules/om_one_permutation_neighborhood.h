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
        OM_OnePermutationNeighborhood(shared_ptr<Benchmark> bench);

        shared_ptr<Neighborhood> spcf_execute(shared_ptr<PSP> psp, shared_ptr<Solution> input);

        //! From Codable
        string codeToSend();

    private:
        shared_ptr<OnePermutationNeighborhood> V;
};
