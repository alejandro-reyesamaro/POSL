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

/*!
 * \class OM_RandomSelection om_random_selection.h
 * \brief Class to represent an Operation Module to select a configuration in a neighborhood
 */
class OM_RandomSelection : public AOM_SelectionFunction
{
    public:
        OM_RandomSelection();

        //! Execute the O.M.
        /*!
        * \param psp The Problem Search Process
        * \param input Input (a neighborhood)
        * \return A random configuration, improving or not the cost
        */
        DecisionPair * spcf_execute(PSP * psp, Neighborhood * input);

        //! From Codable
        string codeToSend();

    private:
        NeighborSelectingRandom * search_strategy;
};
