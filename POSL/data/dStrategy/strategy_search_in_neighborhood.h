#pragma once

/**
 * POSL
 *
 * \file strategy_search_in_neighborhood.h
 * \brief Class to represent a basic search in a set (neighborhood)
 * \author Alejandro Reyes
 * \date 2015-05-28
 */

#include "../neighborhood.h"
#include "../decision_pair.h"
#include "benchmarks/benchmark.h"
#include "solver/psp.h"
#include "v_search_state.h"

/*!
 * \class StrategySearchInNeighborhood strategy_search_in_neighborhood.h
 * \brief Class to represent a basic search in a set (neighborhood)
 */
class StrategySearchInNeighborhood
{
    public:
        //! Constructor
        /*!
        * \param _search_state A search state characterizing every step of the search
        */
        StrategySearchInNeighborhood(VSearchState * _search_state);

        //! Select the the current and the selected configurations when the search state indicates to stop
        /*!
        * \param psp The search process
        * \param V The set (a Neighborhood)
        * \return The current and the new found configurations
        */
        DecisionPair * select(PSP * psp, Neighborhood * V);

    private:
        //! The search state class
        VSearchState * search_state;
};

