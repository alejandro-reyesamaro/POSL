#pragma once

/**
 * POSL
 *
 * \file best_improvement_tabu_v_search_state.h
 * \brief Class to represent a state in a search until finging the best improvement not in a tabu list
 * \author Alejandro Reyes
 * \date 2015-05-28
 */

#include "v_search_state.h"
#include "../../tools/tabu_list.h"

/*!
 * \class BestImprovementTabu_VSearchState best_improvement_tabu_v_search_state.h
 * \brief Class to represent a state in a search until finging the best improvement not in a tabu list
 */
class BestImprovementTabu_VSearchState : public VSearchState
{
    public:
        //! Cosntructor
        BestImprovementTabu_VSearchState(TabuList * _tabu_list);

        //! Indicates to stop when the iterator is over or when the found_cost > current_cost
        /*!
        * \return Returns the best cost not in a tabu list
        */
        bool keepSearching();

        void updateState(Benchmark * _bench,
                         POSL_Iterator<vector<int>> * _it,
                         Solution * current_solution,
                         int _current_cost,
                         Solution * best_solution,
                         int _best_cost,
                         Solution * found_solution,
                         int _found_cost
                         );

    private:
        TabuList * tabu_list;
};
