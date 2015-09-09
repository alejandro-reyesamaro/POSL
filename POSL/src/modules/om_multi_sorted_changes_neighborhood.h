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
        OM_MultiSortedChangesNeighborhood(std::shared_ptr<Benchmark> bench);

        std::shared_ptr<Neighborhood> spcf_execute(std::shared_ptr<PSP> psp, std::shared_ptr<Solution> input);

        //! From Codable
        std::string codeToSend();

    private:
        std::shared_ptr<MultiSortedChangesNeighborhood> V;
};
