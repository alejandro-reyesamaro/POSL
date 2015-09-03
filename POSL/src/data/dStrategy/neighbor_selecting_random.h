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
        DecisionPair * select(PSP * psp, Neighborhood * V);

    private:
        Randomizer * rand;
        DecisionPair * rPair;
        vector<int> best_found_config;
};
