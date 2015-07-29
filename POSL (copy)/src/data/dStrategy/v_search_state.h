#pragma once

/**
 * POSL
 *
 * \file v_search_state.h
 * \brief (Abstract) Class to represent a state in a search
 * \author Alejandro Reyes
 * \date 2015-05-28
 */

#include "../../benchmarks/benchmark.h"
#include "posl_iterator.h"

/*!
 * \class VSearchState v_search_state.h
 * \brief (Abstract) Class to represent a state in a search
 */
class VSearchState
{
    public:
        //! Constructor
        VSearchState();

        //! Updates the search state
        /*!
        * \param _bench A Benchmark
        * \param _it The iterator over some set (neighborhood)
        * \param _current_cost Current cost
        * \param _best_cost Best cost
        * \param _found_cost Tne new found cost
        */
        virtual void updateState(
                Benchmark * _bench,
                POSL_Iterator<vector<int>> * _it,
                Solution * current_solution,
                int _current_cost,
                Solution * best_solution,
                int _best_cost,
                Solution * found_solution,
                int _found_cost
                );
        Solution * GetCurrentSolution();
        Solution * GetFoundSolution();

        //! Indicates whether the search engine keeps searching or not
        /*!
        * \return Returns true or false depending on the state (costs and iterator state)
        */
        virtual bool keepSearching() = 0;

    protected:
        //! The Benchmark
        Benchmark * bench;
        //! Iterato over some set
        POSL_Iterator<vector<int>> * it;
        Solution * current, * best, * found;
        //! The costs
        int current_cost, best_cost, found_cost;
};
