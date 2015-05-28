#pragma once

/**
 * POSL
 *
 * \file best_improvement_v_search_state.h
 * \brief Class to represent a state in a search until finging the best improvement
 * \author Alejandro Reyes
 * \date 2015-05-28
 */

#include "v_search_state.h"

/*!
 * \class BestImprovement_VSearchState best_improvement_v_search_state.h
 * \brief Class to represent a state in a search until finging the best improvement
 */
class BestImprovement_VSearchState : public VSearchState
{
    public:
        //! Constructor
        BestImprovement_VSearchState();

        //! Indicates to stop when the iterator is over
        /*!
        * \return <pc> Returns iterator.HasMoreElements() </pc>
        */
        bool keepSearching();
};
