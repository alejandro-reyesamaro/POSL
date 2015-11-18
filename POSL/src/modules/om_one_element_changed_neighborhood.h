#pragma once

/**
 * POSL
 *
 * \file om_one_element_changed_neighborhood.h
 * \brief Class to represent an Operation Module to generate a neighborhood of a given configuration
 * \author Alejandro Reyes
 * \date 2015-04-14
 */

#include "aom_neighborhood_function.h"
#include "../data/solution.h"
#include "../benchmarks/benchmark.h"
#include "../data/neighborhood.h"
#include "../data/one_element_changed_neighborhood.h"

#define OM_ONE_CHANGE_NEIHBORHOOD_TOK "OM_V.1Change"

/*!
 * \class OM_OneElementChangedNeighborhood om_one_element_changed_neighborhood.h
 * \brief Class to represent an Operation Module to generate a neighborhood of a given configuration
 */
class OM_OneElementChangedNeighborhood : public AOM_NeighborhoodFunction
{
    public:
        OM_OneElementChangedNeighborhood(std::shared_ptr<Benchmark> bench);

        std::shared_ptr<Neighborhood> spcf_execute(std::shared_ptr<PSP>, std::shared_ptr<Solution> input);

        //! From Codable
        std::string codeToSend();

        virtual std::string Tag();

    protected:
        std::shared_ptr<OneElementChangedNeighborhood> V;
};
