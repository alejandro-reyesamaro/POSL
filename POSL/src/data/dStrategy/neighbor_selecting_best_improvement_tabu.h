#pragma once

#include "../neighborhood.h"
#include "../decision_pair.h"
#include "../../benchmarks/benchmark.h"
#include "../../solver/psp.h"
#include "../../tools/tabu_list.h"

class NeighborSelectingBestImprovementTabu
{
    public:
        NeighborSelectingBestImprovementTabu(vector<Domain> domains);

        //! Select the the current and the selected configurations when the search state indicates to stop
        /*!
        * \param psp The search process
        * \param V The set (a Neighborhood)
        * \return The current and the new found configurations
        */
        shared_ptr<DecisionPair> select(shared_ptr<PSP> psp, shared_ptr<Neighborhood> V);

    private:        
        shared_ptr<DecisionPair> rPair;
        shared_ptr<TabuList> tabu_list;
        shared_ptr<POSL_Iterator> it;
        vector<int> current_config;
        vector<int> best_found_config;
        vector<int> neighbor;
};
