#pragma once

/**
 * POSL
 *
 * \file om_best_improvement_selection.h
 * \brief Class to represent an Operation Module to select a configuration in a neighborhood
 * \author Alejandro Reyes
 * \date 2015-04-14
 */

#include "aom_selection_function.h"
#include "../data/dStrategy/neighbor_selecting_best_improvement.h"

/*!
 * \class OM_BestImprovementSelection om_best_improvement_selection.h
 * \brief Class to represent an Operation Module to select a configuration in a neighborhood
 */
class OM_BestImprovementSelection : public AOM_SelectionFunction
{
    public:
        OM_BestImprovementSelection(std::shared_ptr<Benchmark> bench);

        std::shared_ptr<DecisionPair> spcf_execute(std::shared_ptr<PSP> psp, std::shared_ptr<Neighborhood> input);

        //! From Codable
        std::string codeToSend();

        virtual std::string Tag();

    protected:
        std::shared_ptr<NeighborSelectingBestImprovement> search_strategy;        
};
