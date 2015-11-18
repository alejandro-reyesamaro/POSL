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

#define OM_ONE_SORTED_CHANGE_NEIGHBORHOOD_TOK "OM_V.1ChangeOrd"

/*!
 * \class OM_OneSortedChangeNeighborhood om_one_sorted_change_neighborhood.h
 * \brief Class to represent an Operation Module to generate a neighborhood of a given configuration (sorted)
 */
class OM_OneSortedChangeNeighborhood : public AOM_NeighborhoodFunction
{
    public:
        OM_OneSortedChangeNeighborhood(std::shared_ptr<Benchmark> bench);

        std::shared_ptr<Neighborhood> spcf_execute(std::shared_ptr<PSP>, std::shared_ptr<Solution> input);

        //! From Codable
        std::string codeToSend();

        virtual std::string Tag();

    protected:
        std::shared_ptr<OneSortedChangeNeighborhood> V;
};
