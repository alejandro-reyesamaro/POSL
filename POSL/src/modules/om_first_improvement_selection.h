#pragma once

/**
 * POSL
 *
 * \file om_first_improvement_selection.h
 * \brief Class to represent an Operation Module to select a configuration in a neighborhood
 * \author Alejandro Reyes
 * \date 2015-04-14
 */

#include "aom_selection_function.h"
#include "../data/dStrategy/neighbor_selecting_first_improvement.h"

/*!
 * \class OM_FirstImprovementSelection om_first_improvement_selection.h
 * \brief Class to represent an Operation Module to select a configuration in a neighborhood
 */
class OM_FirstImprovementSelection : public AOM_SelectionFunction
{
    public:
        //! Constructor
        OM_FirstImprovementSelection(Benchmark * bench);

        //! Execute the O.M.
        /*!
        * \param psp The Problem Search Process
        * \param input Input (a neighborhood)
        * \return The first configuration improuving the current cost
        */
        DecisionPair * spcf_execute(PSP * psp, Neighborhood * input);

        //! From Codable
        string codeToSend();

    private:
        NeighborSelectingFirstImprovement * search_strategy;
};
