#pragma once

#include "../neighborhood.h"
#include "../decision_pair.h"
#include "../../benchmarks/benchmark.h"
#include "../../solver/psp.h"
#include "../../tools/tabu_list.h"

class NeighborSelectingBestImprovementTabu
{
    public:
        NeighborSelectingBestImprovementTabu();

        //! Select the the current and the selected configurations when the search state indicates to stop
        /*!
        * \param psp The search process
        * \param V The set (a Neighborhood)
        * \return The current and the new found configurations
        */
        DecisionPair * select(PSP * psp, Neighborhood * V);

    private:
        TabuList * tabu_list;
        Solution * current_solution;
        POSL_Iterator<vector<int>> * it;
        vector<int> best_found;
};
