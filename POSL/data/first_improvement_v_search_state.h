#pragma once

/**
 * POSL
 *
 * \file first_improvement_v_search_state.h
 * \brief Class to represent a state in a search until finging the first improvement
 * \author Alejandro Reyes
 * \date 2015-05-28
 */

#include "v_search_state.h"

/*!
 * \class FirstImprovement_VSearchState first_improvement_v_search_state.h
 * \brief Class to represent a state in a search until finging the first improvement
 */
class FirstImprovement_VSearchState : public VSearchState
{
    public:
        //! Cosntructor
        FirstImprovement_VSearchState();

        //! Indicates to stop when the iterator is over or when the found_cost > current_cost
        /*!
        * \return <pc> Returns iterator.HasMoreElements() || found_cost > current_cost </pc>
        */
        bool keepSearching();
};
