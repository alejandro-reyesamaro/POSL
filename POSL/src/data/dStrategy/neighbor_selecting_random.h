#pragma once

#include "../neighborhood.h"
#include "../decision_pair.h"
#include "../../benchmarks/benchmark.h"
#include "../../solver/psp.h"
#include "../../tools/randomizer.h"

class NeighborSelectingRandom
{
    public:
        NeighborSelectingRandom(vector<Domain> domains);

        //! Select the the current and the selected configurations when the search state indicates to stop
        /*!
        * \param psp The search process
        * \param V The set (a Neighborhood)
        * \return The current and the new found configurations
        */
        shared_ptr<DecisionPair> select(shared_ptr<PSP> psp, shared_ptr<Neighborhood> V);

    private:
        shared_ptr<Randomizer> rand;
        shared_ptr<DecisionPair> rPair;
        vector<int> best_found_config;
};
