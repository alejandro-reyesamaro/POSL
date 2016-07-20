#pragma once

#include "aom_selection_function.h"
#include "../data/dStrategy/neighbor_selecting_k_best_improvement.h"
/*!
 * \class OM_FirstImprovementSelection om_first_improvement_selection.h
 * \brief Class to represent an Operation Module to select a configuration in a neighborhood
 */
class OM_KBestImprovementSelection : public AOM_SelectionFunction
{
    public:
        //! Constructor
        OM_KBestImprovementSelection(std::shared_ptr<Benchmark> bench, int k);

        std::shared_ptr<DecisionPair> spcf_execute(std::shared_ptr<PSP> psp, std::shared_ptr<Neighborhood> input);

        //! From Codable
        std::string codeToSend();

        virtual std::string Tag();

    protected:
        std::shared_ptr<NeighborSelectingKBestImprovement> search_strategy;
};
