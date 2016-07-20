#pragma once

#include "aom_selection_function.h"
#include "../data/dStrategy/neighbor_selecting_heuristic_first_improvement.h"

class OM_HFirstImprovementSelection : public AOM_SelectionFunction
{
    public:
        //! Constructor
        OM_HFirstImprovementSelection(std::shared_ptr<Benchmark> bench);

        std::shared_ptr<DecisionPair> spcf_execute(std::shared_ptr<PSP> psp, std::shared_ptr<Neighborhood> input);

        //! From Codable
        std::string codeToSend();

        virtual std::string Tag();

    protected:
        std::shared_ptr<NeighborSelectingHeuristicFirstImprovement> search_strategy;
};
