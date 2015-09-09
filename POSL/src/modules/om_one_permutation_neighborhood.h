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
        OM_OnePermutationNeighborhood(std::shared_ptr<Benchmark> bench);

        std::shared_ptr<Neighborhood> spcf_execute(std::shared_ptr<PSP> psp, std::shared_ptr<Solution> input);

        //! From Codable
        std::string codeToSend();

    private:
        std::shared_ptr<OnePermutationNeighborhood> V;
};
