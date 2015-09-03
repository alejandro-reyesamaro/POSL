#pragma once

/**
 * POSL
 *
 * \file om_best_improvement_tabu_selection.h
 * \brief Class to represent an Operation Module to select a configuration in a neighborhood
 * \author Alejandro Reyes
 * \date 2015-07-06
 */

#include "aom_selection_function.h"
#include "../tools/tabu_list.h"
#include "../data/dStrategy/neighbor_selecting_best_improvement_tabu.h"

/*!
 * \class OM_BestImprovementTabuSelection om_best_improvement_tabu_selection.h
 * \brief Class to represent an Operation Module to select a configuration in a neighborhood
 */
class OM_BestImprovementTabuSelection : public AOM_SelectionFunction
{
    public:
        OM_BestImprovementTabuSelection(Benchmark * bench);

        //! Execute the O.M.
        /*!
        * \param psp The Problem Search Process
        * \param input Input (a neighborhood)
        * \return The configuration that improuves the best the current cost not in a tabu list
        */
        DecisionPair * spcf_execute(PSP * psp, Neighborhood * input);

        //! From Codable
        string codeToSend();

    private:
        NeighborSelectingBestImprovementTabu * search_strategy;
};
