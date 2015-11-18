#pragma once


/**
 * POSL
 *
 * \file om_random_selection.h
 * \brief Class to represent an Operation Module to select a configuration in a neighborhood
 * \author Alejandro Reyes
 * \date 2015-07-06
 */

#include "aom_selection_function.h"
#include "../data/dStrategy/neighbor_selecting_random.h"

#define OM_RANDOM_SELECTION_TOK "OM_SS.Rand"

/*!
 * \class OM_RandomSelection om_random_selection.h
 * \brief Class to represent an Operation Module to select a configuration in a neighborhood
 */
class OM_RandomSelection : public AOM_SelectionFunction
{
    public:
        OM_RandomSelection(std::shared_ptr<Benchmark> bench);

        std::shared_ptr<DecisionPair> spcf_execute(std::shared_ptr<PSP> psp, std::shared_ptr<Neighborhood> input);

        //! From Codable
        std::string codeToSend();

        virtual std::string Tag();

    protected:
        std::shared_ptr<NeighborSelectingRandom> search_strategy;
};
