#pragma once

#include "../neighborhood.h"
#include "../decision_pair.h"
#include "../../benchmarks/benchmark.h"
#include "../../solver/psp.h"

class NeighborSelectingFirstImprovement
{
    public:
        NeighborSelectingFirstImprovement(std::vector<Domain> domains);

        //! Select the the current and the selected configurations when the search state indicates to stop
        /*!
        * \param psp The search process
        * \param V The set (a Neighborhood)
        * \return The current and the new found configurations
        */
        std::shared_ptr<DecisionPair> select(std::shared_ptr<PSP> psp, std::shared_ptr<Neighborhood> V);

    private:
        std::shared_ptr<DecisionPair> rPair;
        std::shared_ptr<POSL_Iterator> it;
        std::vector<int> current_config;
        std::vector<int> best_found_config;
        std::vector<int> neighbor;
};
