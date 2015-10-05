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
        OM_BestImprovementTabuSelection(shared_ptr<Benchmark> bench);

        shared_ptr<DecisionPair> spcf_execute(shared_ptr<PSP> psp, shared_ptr<Neighborhood> input);

        //! From Codable
        string codeToSend();

        std::string TAG();

    protected:
        shared_ptr<NeighborSelectingBestImprovementTabu> search_strategy;
};
