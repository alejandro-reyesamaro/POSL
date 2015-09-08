#pragma once

/**
 * POSL
 *
 * \file om_multi_elements_changed_neighborhood.h
 * \brief Class to represent an Operation Module to generate a neighborhood of a given configuration
 * \author Alejandro Reyes
 * \date 2015-04-14
 */

#include "aom_neighborhood_function.h"
#include "../data/solution.h"
#include "../benchmarks/benchmark.h"
#include "../data/neighborhood.h"
#include "../data/multi_elements_changed_neighborhood.h"

/*!
 * \class OM_MultiElementsChangedNeighborhood om_multi_elements_changed_neighborhood.h
 * \brief Class to represent an Operation Module to generate a neighborhood of a given configuration
 */
class OM_MultiElementsChangedNeighborhood : public AOM_NeighborhoodFunction
{
    public:
        //! Constructor
        OM_MultiElementsChangedNeighborhood(shared_ptr<Benchmark> bench);

        shared_ptr<Neighborhood> spcf_execute(shared_ptr<PSP> psp, shared_ptr<Solution> input);

        //! From Codable
        string codeToSend();

    private:
        shared_ptr<MultiElementsChangedNeighborhood> V;
};
